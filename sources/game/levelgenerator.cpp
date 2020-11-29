#include <ctime>

#include "sources/game/levelgenerator.h"
#include "sources/game/objects/medicines/medicinesfactory.h"
#include "sources/game/objects/weapon/weaponfactory.h"
#include "sources/game/objects/armor/armorfactory.h"
#include "sources/game/objects/levelpassobject/levelpassobjectfactory.h"


void LevelGenerator::generateRoomCells(Position2D room_position, RoomType type, size_t entry_top_room_x) {
    Field& field = Field::getInstance();

    if (Field::isCreated()) {
        CellType cell_type_map[12][12];
        bool entry_left = room_position.x != 0;
        bool entry_top = room_position.y != 0 && room_position.x == entry_top_room_x;

        for (size_t y = 0; y < 12; y++) {
            for (size_t x = 0; x < 12; x++) {
                cell_type_map[y][x] = CellType::Empty;
            }
        }

        for (size_t i = 0; i < 12; i++) {
            if (i == 5 || i == 6 || i == 7) {
                if (!entry_top) {
                    cell_type_map[0][i] = CellType::Wall;
                }

                if (!entry_left) {
                    cell_type_map[i][0] = CellType::Wall;
                }

            } else {
                cell_type_map[0][i] = CellType::Wall;
                cell_type_map[i][0] = CellType::Wall;
            }
        }

        if (type == RoomType::Columns) {
            cell_type_map[4][4] = CellType::Wall;
            cell_type_map[8][4] = CellType::Wall;
            cell_type_map[4][8] = CellType::Wall;
            cell_type_map[8][8] = CellType::Wall;
        } else if (type == RoomType::Room) {
            int room_entry = rand() % 4;

            for (size_t y = 4; y < 9; y++) {
                for (size_t x = 4; x < 9; x++) {
                    if ((y == 4 && room_entry != 0) ||
                        (y == 8 && room_entry != 1) ||
                        (x == 4 && room_entry != 2) ||
                        (x == 8 && room_entry != 3)) {
                        cell_type_map[y][x] = CellType::Wall;
                    }
                }
            }
        }

        for (size_t x = 0; x < 12; x++) {
            for (size_t y = 0; y < 12; y++) {
                Position2D position(12 * room_position.x + x, 12 * room_position.y + y);
                field.getCell(position).changeType(cell_type_map[y][x]);
            }
        }
    }
}


void LevelGenerator::generateRoomObjects(Position2D room_position, RoomType type) {
    sharedObjectFactory factory;

    switch(rand() % 3) {
    case 0:
        factory = sharedObjectFactory(new MedicinesFactory);
        break;
    case 1:
        factory = sharedObjectFactory(new ArmorFactory);
        break;
    case 2:
        factory = sharedObjectFactory(new WeaponFactory);
        break;
    }

    if (type == RoomType::Room) {
        for (size_t y = 5; y < 8; y++) {
            for (size_t x = 5; x < 8; x++) {
                if (rand() % 10 == 0) {
                    Position2D position(12 * room_position.x + x, 12 * room_position.y + y);
                    sharedObject object = factory->createObject();
                    placeObject(position, object);
                }
            }
        }
    } else {
        Position2D position(12 * room_position.x + rand() % 10 + 1, 12 * room_position.y + rand() % 10 + 1);
        sharedObject object = factory->createObject();
        placeObject(position, object);
    }
}


LevelGenerator::LevelGenerator(const sharedLoggingListener& logger)
    : logger_(logger), difficult_(0) {}


void LevelGenerator::generate(Size2D room_count, int difficult) {
    Field::deleteInstance();
    difficult_ = difficult;

    if (room_count.x == 0 || room_count.y == 0) {
        return;
    }

    srand(time(nullptr));

    Size2D field_size = Size2D(12 * room_count.x + 1, 12 * room_count.y + 1);
    Field& field = Field::initInstance(field_size);

    for (size_t roomY = 0; roomY < room_count.y; roomY++) {
        size_t entry_top_room_x = rand() % room_count.x;

        for (size_t roomX = 0; roomX < room_count.x; roomX++) {
            Position2D room_position(roomX, roomY);
            RoomType roomType = static_cast<RoomType>(rand() % 3);

            generateRoomCells(room_position, roomType, entry_top_room_x);
            generateRoomObjects(room_position, roomType);
        }
    }

    for (size_t i = 0; i < field_size.x; i++) {
        field.getCell(Position2D(i, field_size.y - 1)).changeType(CellType::Wall);
    }

    for (size_t i = 0; i < field_size.y; i++) {
        field.getCell(Position2D(field_size.x - 1, i)).changeType(CellType::Wall);
    }

    entry_ = Position2D(2, 2);
    field.getCell(entry_).changeType(CellType::Entry);

    Position2D exit = Position2D(field_size.x - 2, field_size.y - 2);
    field.getCell(exit).changeType(CellType::Exit);

    sharedLevelPassObjectFactory levelPassFactory = std::make_shared<LevelPassObjectFactory>();
    sharedObject object = levelPassFactory->createObject();
    Position2D level_pass_object_position(rand() % field_size.x, rand() % field_size.y);

    while (field.getCell(level_pass_object_position).getType() != CellType::Empty) {
        level_pass_object_position = Position2D(rand() % field_size.x, rand() % field_size.y);
    }

    placeObject(level_pass_object_position, object);
}

void LevelGenerator::spawnEnemies(std::vector<sharedCreature>& enemies, int difficult) {
    difficult_ = difficult;
    enemies.push_back(createEnemy<MovementPolicy::Stand, AttackPolicy::Distance>(Position2D(9, 9)));
}


void LevelGenerator::placeObject(Position2D position, const sharedObject& object) {
    object->getEventManager().subscribe(logger_);

    if (Field::isCreated()) {
        Field::getInstance().getCell(position).setObject(object);
    }
}


Position2D LevelGenerator::getEntryPosition() const {
    return entry_;
}


template<MovementPolicy movement_policy, AttackPolicy attack_policy>
sharedEnemy<movement_policy, attack_policy> LevelGenerator::createEnemy(const Position2D& position) {
    sharedEnemy<movement_policy, attack_policy> enemy = std::make_shared<Enemy<movement_policy, attack_policy>>(position);
    enemy->setMaxHealth(100 + difficult_ * 50);
    enemy->setHealth(100 + difficult_ * 50);
    enemy->setAttackDamage(1 + difficult_ * 2);
    enemy->setProtection(0 + difficult_);
    enemy->getEventManager().subscribe(logger_);
    return enemy;
}
