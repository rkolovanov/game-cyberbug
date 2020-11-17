#include "classes/game/levelgenerator.h"
#include "classes/game/objects/medicines/medicinesfactory.h"
#include "classes/game/objects/weapon/weaponfactory.h"
#include "classes/game/objects/armor/armorfactory.h"
#include "classes/game/objects/levelpassobject/levelpassobjectfactory.h"
#include <ctime>

void LevelGenerator::generateRoomCells(Position2D roomPosition, RoomType type, size_t entryTopRoomX) {
    Field& field = Field::getInstance();

    if (Field::isCreated()) {
        CellType cellTypeMap[12][12];
        bool entryLeft = roomPosition.x != 0;
        bool entryTop = roomPosition.y != 0 && roomPosition.x == entryTopRoomX;

        for (size_t y = 0; y < 12; y++) {
            for (size_t x = 0; x < 12; x++) {
                cellTypeMap[y][x] = CellType::Empty;
            }
        }

        for (size_t i = 0; i < 12; i++) {
            if (i == 5 || i == 6 || i == 7) {
                if (!entryTop) {
                    cellTypeMap[0][i] = CellType::Wall;
                }

                if (!entryLeft) {
                    cellTypeMap[i][0] = CellType::Wall;
                }

            } else {
                cellTypeMap[0][i] = CellType::Wall;
                cellTypeMap[i][0] = CellType::Wall;
            }
        }

        if (type == RoomType::Columns) {
            cellTypeMap[4][4] = CellType::Wall;
            cellTypeMap[8][4] = CellType::Wall;
            cellTypeMap[4][8] = CellType::Wall;
            cellTypeMap[8][8] = CellType::Wall;
        } else if (type == RoomType::Room) {
            int roomEntry = rand() % 4;
            for (size_t y = 4; y < 9; y++) {
                for (size_t x = 4; x < 9; x++) {
                    if ((y == 4 && roomEntry != 0) ||
                        (y == 8 && roomEntry != 1) ||
                        (x == 4 && roomEntry != 2) ||
                        (x == 8 && roomEntry != 3)) {
                        cellTypeMap[y][x] = CellType::Wall;
                    }
                }
            }
        }

        for (size_t x = 0; x < 12; x++) {
            for (size_t y = 0; y < 12; y++) {
                Position2D position(12 * roomPosition.x + x, 12 * roomPosition.y + y);
                field.getCell(position).changeType(cellTypeMap[y][x]);
            }
        }
    }
}

void LevelGenerator::generateRoomObjects(Position2D roomPosition, RoomType type) {
    pObjectFactory factory;

    switch(rand() % 3) {
    case 0:
        factory = pObjectFactory(new MedicinesFactory);
        break;
    case 1:
        factory = pObjectFactory(new ArmorFactory);
        break;
    case 2:
        factory = pObjectFactory(new WeaponFactory);
        break;
    }

    if (type == RoomType::Room) {
        for (size_t y = 5; y < 8; y++) {
            for (size_t x = 5; x < 8; x++) {
                if (rand() % 10 == 0) {
                    Position2D position(12 * roomPosition.x + x, 12 * roomPosition.y + y);
                    pObject object = factory->createObject();
                    placeObject(position, object);
                }
            }
        }
    } else {
        Position2D position(12 * roomPosition.x + rand() % 10 + 1, 12 * roomPosition.y + rand() % 10 + 1);
        pObject object = factory->createObject();
        placeObject(position, object);
    }
}

LevelGenerator::LevelGenerator(pLoggingListener& logger): logger_(logger), difficult_(0) {}

void LevelGenerator::generate(Size2D roomCount, int difficult) {
    Field::deleteInstance();
    difficult_ = difficult;

    if (roomCount.x == 0 || roomCount.y == 0) {
        return;
    }

    srand(time(nullptr));

    Size2D fieldSize = Size2D(12 * roomCount.x + 1, 12 * roomCount.y + 1);
    Field& field = Field::initInstance(fieldSize);

    for (size_t roomY = 0; roomY < roomCount.y; roomY++) {
        size_t entryTopRoomX = rand() % roomCount.x;

        for (size_t roomX = 0; roomX < roomCount.x; roomX++) {
            Position2D roomPosition(roomX, roomY);
            RoomType roomType = static_cast<RoomType>(rand() % 3);

            generateRoomCells(roomPosition, roomType, entryTopRoomX);
            generateRoomObjects(roomPosition, roomType);
        }
    }

    for (size_t i = 0; i < fieldSize.x; i++) {
        field.getCell(Position2D(i, fieldSize.y - 1)).changeType(CellType::Wall);
    }

    for (size_t i = 0; i < fieldSize.y; i++) {
        field.getCell(Position2D(fieldSize.x - 1, i)).changeType(CellType::Wall);
    }

    entry_ = Position2D(2, 2);
    field.getCell(entry_).changeType(CellType::Entry);

    Position2D exit = Position2D(fieldSize.x - 2, fieldSize.y - 2);
    field.getCell(exit).changeType(CellType::Exit);

    pLevelPassObjectFactory levelPassFactory(new LevelPassObjectFactory);
    pObject object = levelPassFactory->createObject();
    Position2D levelPassObjectPosition(rand() % fieldSize.x, rand() % fieldSize.y);
    while (field.getCell(levelPassObjectPosition).getType() != CellType::Empty) {
        levelPassObjectPosition = Position2D(rand() % fieldSize.x, rand() % fieldSize.y);
    }
    placeObject(levelPassObjectPosition, object);
}

void LevelGenerator::placeObject(Position2D position, pObject& object) {
    pEventListener listener(logger_);
    object->getEventManager().subscribe(listener);

    if (Field::isCreated()) {
        Field::getInstance().getCell(position).setObject(object);
    }
}

Position2D LevelGenerator::getEntryPosition() const {
    return entry_;
}
