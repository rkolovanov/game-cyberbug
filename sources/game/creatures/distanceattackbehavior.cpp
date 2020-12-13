#include "sources/game/creatures/distanceattackbehavior.h"

namespace game {


void game::DistanceAttackBehavior::attack(Creature& creature, sharedCreature& target) {
    Position2D target_position = target->getPosition();
    Position2D creature_position = creature.getPosition();

    long long delta_x = static_cast<long long>(target_position.x) - static_cast<long long>(creature_position.x);
    long long delta_y = static_cast<long long>(target_position.y) - static_cast<long long>(creature_position.y);

    if (delta_x > 0 && delta_y == 0 && std::abs(delta_x) < 4) {
        creature.setRotation(Direction::Right);
    } else if (delta_x < 0 && delta_y == 0 && std::abs(delta_x) < 4) {
        creature.setRotation(Direction::Left);
    } else if (delta_y > 0 && delta_x == 0 && std::abs(delta_y) < 4) {
        creature.setRotation(Direction::Bottom);
    } else if (delta_y < 0 && delta_x == 0 && std::abs(delta_y) < 4) {
        creature.setRotation(Direction::Top);
    } else {
        return;
    }

    creature <= target;
}


};
