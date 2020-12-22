#include <iostream>

#include "sources/game/field.h"
#include "sources/game/gamesaver.h"
#include "sources/common/exception.h"
#include "sources/game/objects/armor/armor.h"
#include "sources/game/objects/weapon/weapon.h"
#include "sources/game/objects/medicines/medicines.h"
#include "sources/game/creatures/enemies/enemy.h"
#include "sources/game/creatures/player/playermemento.h"
#include "sources/game/objects/levelpassobject/levelpassobject.h"
#include "sources/game/creatures/meleeattackbehavior.h"
#include "sources/game/creatures/distanceattackbehavior.h"
#include "sources/game/creatures/standmovementbehavior.h"
#include "sources/game/creatures/walkmovementbehavior.h"

namespace game {


game::GameSaver::GameSaver(const std::string& path, const sharedEventListener& logging_listener): error_(false) {
    file_.open(path, std::ios::binary);
    event_manager_.subscribe(logging_listener);

    if (!file_.is_open()) {
        event_manager_.notify("Cannot open file: " + path);
        error_ = true;
        file_.close();
    }
}


game::GameSaver::~GameSaver() {
    if (!error_) {
        file_.close();
    }
}


bool game::GameSaver::isInvalid() const {
    return error_;
}


void game::GameSaver::save(const sharedPlayer& player, const Enemies& enemies, size_t level) {
    if (isInvalid()) {
        return;
    }

    std::ostringstream message_stream;
    FieldMemento field_snapshot = Field::getInstance().save();
    sharedCellTable cells = field_snapshot.getCellTable();
    Size2D size = field_snapshot.getSize();

    message_stream << "Writing: Level(" << level << ")";
    event_manager_.notify(message_stream);
    message_stream = std::ostringstream();

    file_.write((char*)(&level), sizeof(int));

    message_stream << "Writing: Size2D" << size << " of class Field";
    event_manager_.notify(message_stream);
    message_stream = std::ostringstream();

    file_.write((char*)(&size), sizeof(Size2D));

    if (cells == nullptr) {
        return;
    }

    for (size_t y = 0; y < size.y; y++) {
        for (size_t x = 0; x < size.x; x++) {
            const Cell& cell = cells->at(y).at(x);

            CellType cell_type = cell.getType();
            Position2D cell_position = cell.getPosition();
            sharedConstObject cell_object = cell.getObject();
            bool cell_has_object = (cell_object != nullptr);

            file_.write((char*)(&cell_position), sizeof(Position2D));
            file_.write((char*)(&cell_type), sizeof(CellType));
            file_.write((char*)(&cell_has_object), sizeof(bool));

            message_stream << "Writing: Cell(Position: " << cell_position
                           << ", Type: " << static_cast<int>(cell_type)
                           << ", HasObject: " << cell_has_object << ")";

            if (cell_has_object) {
                size_t type_hash = cell_object->getClass().hash_code();

                file_.write((char*)(&type_hash), sizeof(size_t));

                message_stream << " and Object(Hash: " << type_hash << ")";

                if (cell_object->getClass() == typeid(Medicines)) {
                    const Medicines& medicines = dynamic_cast<const Medicines&>(*cell_object);
                    int health_recovery = medicines.getHealthRecovery();
                    file_.write((char*)(&health_recovery), sizeof(int));
                } else if (cell_object->getClass() == typeid(Armor)) {
                    const Armor& armor = dynamic_cast<const Armor&>(*cell_object);
                    int protection = armor.getProtection();
                    file_.write((char*)(&protection), sizeof(int));
                } else if (cell_object->getClass() == typeid(Weapon)) {
                    const Weapon& weapon = dynamic_cast<const Weapon&>(*cell_object);
                    int damage = weapon.getDamage();
                    file_.write((char*)(&damage), sizeof(int));
                }
            }

            event_manager_.notify(message_stream);
            message_stream = std::ostringstream();
        }
    }

    event_manager_.notify("Writing: Player");

    PlayerMemento player_snapshot = player->save();
    file_.write((char*)(&player_snapshot), sizeof(PlayerMemento));

    event_manager_.notify("Writing: Enemies size");

    size_t enemies_size = enemies.size();
    file_.write((char*)(&enemies_size), sizeof(size_t));

    for (auto& enemy : enemies) {
        EnemyMemento enemy_snapshot = enemy->save();
        file_.write((char*)(&enemy_snapshot), sizeof(EnemyMemento));

        message_stream << "Writing: Enemy(Position: " << enemy_snapshot.getPosition() << ")";
        event_manager_.notify(message_stream);
        message_stream = std::ostringstream();
    }
}


};
