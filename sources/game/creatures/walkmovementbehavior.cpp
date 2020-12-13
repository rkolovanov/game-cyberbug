#include "sources/game/creatures/walkmovementbehavior.h"

namespace game {


Position2D game::WalkMovementBehavior::getMovementPosition(Creature& creature, const Position2D& target_position) {
    Position2D creature_position = creature.getPosition();

    long long delta_x = static_cast<long long>(target_position.x) - static_cast<long long>(creature_position.x);
    long long delta_y = static_cast<long long>(target_position.y) - static_cast<long long>(creature_position.y);

    if (std::abs(delta_x) > std::abs(delta_y)) {
        if (delta_x > 0) {
            creature_position.shift(Direction::Right);
            creature.setRotation(Direction::Right);
        } else if (delta_x < 0) {
            creature_position.shift(Direction::Left);
            creature.setRotation(Direction::Left);
        } else if (delta_y > 0) {
            creature_position.shift(Direction::Bottom);
            creature.setRotation(Direction::Bottom);
        } else if (delta_y < 0) {
            creature_position.shift(Direction::Top);
            creature.setRotation(Direction::Top);
        }
    } else {
        if (delta_y > 0) {
            creature_position.shift(Direction::Bottom);
            creature.setRotation(Direction::Bottom);
        } else if (delta_y < 0) {
            creature_position.shift(Direction::Top);
            creature.setRotation(Direction::Top);
        } else if (delta_x > 0) {
            creature_position.shift(Direction::Right);
            creature.setRotation(Direction::Right);
        } else if (delta_x < 0) {
            creature_position.shift(Direction::Left);
            creature.setRotation(Direction::Left);
        }
    }

    return creature_position;
}


};
