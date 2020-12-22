#include "sources/game/gameloader.h"
#include "sources/game/field.h"
#include "sources/game/fieldmemento.h"
#include "sources/common/exception.h"
#include "sources/game/objects/armor/armorfactory.h"
#include "sources/game/objects/levelpassobject/levelpassobjectfactory.h"
#include "sources/game/objects/weapon/weaponfactory.h"
#include "sources/game/objects/medicines/medicinesfactory.h"
#include "sources/game/creatures/enemies/enemy.h"

namespace game {


game::GameLoader::GameLoader(const std::string& path, const sharedEventListener& logging_listener): logging_listener_(logging_listener), error_(false) {
    file_.open(path, std::ios::binary);
    event_manager_.subscribe(logging_listener);

    if (!file_.is_open()) {
        event_manager_.notify("Cannot open file: " + path);
        error_ = true;
        file_.close();
    }
}


game::GameLoader::~GameLoader() {
    if (!error_) {
        file_.close();
    }
}


bool game::GameLoader::isInvalid() const {
    return error_;
}


void game::GameLoader::load(sharedPlayer& player, Enemies& enemies, size_t& level) {
    if (isInvalid()) {
        return;
    }

    std::ostringstream message_stream;
    Size2D field_size;
    int level_snapshot;

    if (file_.eof()) {
        throw Exception("Error with reading save");
    }

    file_.read((char*)(&level_snapshot), sizeof(int));

    message_stream << "Reading: Level(" << level_snapshot << ")";
    event_manager_.notify(message_stream);
    message_stream = std::ostringstream();

    if (file_.eof()) {
        throw Exception("Error with reading save");
    }

    file_.read((char*)(&field_size), sizeof(Size2D));

    message_stream << "Reading: Size2D" << field_size << " of class Field";
    event_manager_.notify(message_stream);
    message_stream = std::ostringstream();

    if (field_size.x == 0 || field_size.y == 0) {
        throw Exception("Invalid field size! Field size: ("
                        + std::to_string(field_size.x) + ", "
                        + std::to_string(field_size.y) + ")");
    }

    sharedCellTable field_cells = std::make_shared<CellTable>(field_size.y);
    sharedArmorFactory armor_factory = std::make_shared<ArmorFactory>();
    sharedWeaponFactory weapon_factory = std::make_shared<WeaponFactory>();
    sharedMedicinesFactory medicines_factory = std::make_shared<MedicinesFactory>();
    sharedLevelPassObjectFactory level_pass_factory = std::make_shared<LevelPassObjectFactory>();

    for (size_t y = 0; y < field_size.y; y++) {
        CellRow& row = field_cells->at(y);
        row.resize(field_size.x);

        for (size_t x = 0; x < field_size.x; x++) {
            Cell& cell = field_cells->at(y).at(x);

            CellType cell_type = cell.getType();
            Position2D cell_position = cell.getPosition();
            sharedConstObject cell_object = cell.getObject();
            bool cell_has_object = (cell_object != nullptr);

            if (file_.eof()) {
                throw Exception("Error with reading save");
            }

            file_.read((char*)(&cell_position), sizeof(Position2D));
            file_.read((char*)(&cell_type), sizeof(CellType));
            file_.read((char*)(&cell_has_object), sizeof(bool));

            cell = Cell(cell_position);
            cell.changeType(cell_type);

            message_stream << "Readed: Cell(Passable - " << cell.getPassable()
                           << ", Type - " << (int)cell.getType()
                           << ", Position - " << cell.getPosition()
                           << ", HasObject - " << cell_has_object << ")";

            if (cell_has_object) {
                size_t type_hash;
                sharedObject object;

                if (file_.eof()) {
                    throw Exception("Error with reading save");
                }

                file_.read((char*)(&type_hash), sizeof(size_t));

                message_stream << "and Object(Hash: " << type_hash << ")";

                if (file_.eof()) {
                    throw Exception("Error with reading save");
                }

                if (type_hash == typeid(Armor).hash_code()) {
                    int protection;
                    file_.read((char*)(&protection), sizeof(int));
                    object = armor_factory->createArmor(protection);
                } else if (type_hash == typeid(Weapon).hash_code()) {
                    int damage;
                    file_.read((char*)(&damage), sizeof(int));
                    object = weapon_factory->createWeapon(damage);
                } else if (type_hash == typeid(Medicines).hash_code()) {
                    int health_recovery;
                    file_.read((char*)(&health_recovery), sizeof(int));
                    object = medicines_factory->createMedicines(health_recovery);
                } else if (type_hash == typeid(LevelPassObject).hash_code()){
                    object = level_pass_factory->createObject();
                } else {
                    throw Exception("Unknown object class! Type hash: " + std::to_string(type_hash));
                }

                if (object != nullptr) {
                    object->getEventManager().subscribe(logging_listener_);
                    cell.setObject(object);
                }
            }

            event_manager_.notify(message_stream);
            message_stream = std::ostringstream();
        }
    }

    FieldMemento field_snapshot(field_cells, field_size);

    event_manager_.notify("Reading: Player");

    PlayerMemento player_snapshot;

    if (file_.eof()) {
        throw Exception("Error with reading save");
    }

    file_.read((char*)(&player_snapshot), sizeof(PlayerMemento));

    size_t enemies_size = enemies.size();

    if (file_.eof()) {
        throw Exception("Error with reading save");
    }

    file_.read((char*)(&enemies_size), sizeof(size_t));

    event_manager_.notify("Reading: Enemies size (" + std::to_string(enemies_size) + ")");

    Enemies enemies_snapshot;
    for (size_t i = 0; i < enemies_size; i++) {
        sharedAbstractEnemy enemy;
        EnemyMemento enemy_snapshot;

        if (file_.eof()) {
            throw Exception("Error with reading save");
        }

        file_.read((char*)(&enemy_snapshot), sizeof(EnemyMemento));

        message_stream << "Reading: Enemy(Position: " << enemy_snapshot.getPosition() <<
                          ", Health: " << enemy_snapshot.getHealth() <<
                          ", Max Health: " << enemy_snapshot.getMaxHealth() <<
                          ", Protection: " << enemy_snapshot.getProtection() <<
                          ", Rotation: " << (int)enemy_snapshot.getRotation() <<
                          ", Damage: " << enemy_snapshot.getAttackDamage() <<
                          ", Attack Behavior: " << enemy_snapshot.getAttackBehaviorHash() <<
                          ", Movement Behavior: " << enemy_snapshot.getMovementBehaviorHash() <<
                          ")";
        event_manager_.notify(message_stream);
        message_stream = std::ostringstream();

        if (enemy_snapshot.getAttackBehaviorHash() == typeid(game::MeleeAttackBehavior).hash_code()) {
            if (enemy_snapshot.getMovementBehaviorHash() == typeid(game::StandMovementBehavior).hash_code()) {
                enemy = std::make_shared<Enemy<StandMovementBehavior, MeleeAttackBehavior>>(enemy_snapshot.getPosition());
            } else if (enemy_snapshot.getMovementBehaviorHash() == typeid(game::WalkMovementBehavior).hash_code()) {
                enemy = std::make_shared<Enemy<WalkMovementBehavior, MeleeAttackBehavior>>(enemy_snapshot.getPosition());
            } else {
                throw Exception("Unknown enemy movement behavior: " + std::to_string(enemy_snapshot.getMovementBehaviorHash()));
            }
        } else if (enemy_snapshot.getAttackBehaviorHash() == typeid(game::DistanceAttackBehavior).hash_code()) {
            if (enemy_snapshot.getMovementBehaviorHash() == typeid(game::StandMovementBehavior).hash_code()) {
                enemy = std::make_shared<Enemy<StandMovementBehavior, DistanceAttackBehavior>>(enemy_snapshot.getPosition());
            } else if (enemy_snapshot.getMovementBehaviorHash() == typeid(game::WalkMovementBehavior).hash_code()) {
                enemy = std::make_shared<Enemy<WalkMovementBehavior, DistanceAttackBehavior>>(enemy_snapshot.getPosition());
            } else {
                throw Exception("Unknown enemy movement behavior: " + std::to_string(enemy_snapshot.getMovementBehaviorHash()));
            }
        } else {
            throw Exception("Unknown enemy attack behavior: " + std::to_string(enemy_snapshot.getAttackBehaviorHash()));
        }

        enemy->restore(enemy_snapshot);
        enemy->getEventManager().subscribe(logging_listener_);
        enemies_snapshot.push_back(enemy);
    }

    level = level_snapshot;
    Field::getInstance().restore(field_snapshot);
    player->restore(player_snapshot);
    enemies.clear();
    enemies = enemies_snapshot;
    event_manager_.notify("Loading complete!");
}


};
