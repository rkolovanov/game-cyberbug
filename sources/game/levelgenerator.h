#ifndef SOURCES_GAME_LEVEL_GENERATOR_H
#define SOURCES_GAME_LEVEL_GENERATOR_H

#include "sources/common/point2d.h"
#include "sources/game/celltype.h"
#include "sources/game/roomtype.h"
#include "sources/game/objects/object.h"
#include "sources/game/field.h"
#include "sources/logging/logginglistener.h"
#include "sources/game/objects/creatures/enemies/enemy.h"


class LevelGenerator final {
private:
    sharedLoggingListener logger_;
    Position2D entry_;
    int difficult_;

    void generateRoomCells(Position2D room_position, RoomType type, size_t entry_top_room_x = 0);
    void generateRoomObjects(Position2D room_position, RoomType type);

public:
    LevelGenerator(const sharedLoggingListener& logger);

    void generate(Size2D room_count, int difficult = 0);
    void spawnEnemies(std::vector<sharedCreature>& enemies, int difficult = 0);
    void placeObject(Position2D position, const sharedObject& object);
    Position2D getEntryPosition() const;

    template<MovementPolicy movement_policy, AttackPolicy attack_policy>
    sharedEnemy<movement_policy, attack_policy> createEnemy(const Position2D& position);
}; // class LevelGenerator


#endif // SOURCES_GAME_LEVEL_GENERATOR_H
