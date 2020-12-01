#include "sources/game/objects/creatures/meleeattackbehavior.h"


void MeleeAttackBehavior::attack(Creature& creature, sharedCreature& target) {
    Position2D target_position = target->getPosition();
    Position2D creature_position = creature.getPosition();

    if (Position2D(creature_position.x + 1, creature_position.y) == target_position) {
        creature.setRotation(Direction::Right);
    } else if (Position2D(creature_position.x - 1, creature_position.y) == target_position) {
        creature.setRotation(Direction::Left);
    } else if (Position2D(creature_position.x, creature_position.y + 1) == target_position) {
        creature.setRotation(Direction::Bottom);
    } else if (Position2D(creature_position.x, creature_position.y - 1) == target_position) {
        creature.setRotation(Direction::Top);
    } else {
        return;
    }

    creature <= target;
}
