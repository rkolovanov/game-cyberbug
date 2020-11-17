#ifndef LEVEL_GENERATOR_H
#define LEVEL_GENERATOR_H

#include "classes/common/point2d.h"
#include "classes/enumerations/celltype.h"
#include "classes/enumerations/roomtype.h"
#include "classes/game/objects/object.h"
#include "classes/game/field.h"
#include "classes/logging/logginglistener.h"


class LevelGenerator {
private:
    pLoggingListener logger_;
    Position2D entry_;
    int difficult_;

    void generateRoomCells(Position2D roomPosition, RoomType type, size_t entryTopRoomX = 0);
    void generateRoomObjects(Position2D roomPosition, RoomType type);

public:
    LevelGenerator(pLoggingListener& logger);
    void generate(Size2D roomCount, int difficult = 0);
    void placeObject(Position2D position, pObject& object);
    Position2D getEntryPosition() const;
};


#endif // LEVEL_GENERATOR_H
