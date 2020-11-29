#ifndef SOURCES_GAME_OBJECTS_CREATURES_ENEMY_ENEMY_H
#define SOURCES_GAME_OBJECTS_CREATURES_ENEMY_ENEMY_H

#include <memory>

#include "sources/game/objects/creatures/creature.h"
#include "sources/game/interactions/interactionnone.h"
#include "sources/game/objects/creatures/movementpolicy.h"
#include "sources/game/objects/creatures/attackpolicy.h"


template<MovementPolicy movement_policy, AttackPolicy attack_policy>
class Enemy final: public Creature {
public:
    explicit Enemy(Position2D position);
    ~Enemy() override;

    virtual void operator<=(sharedObject& object) override;
    virtual void operator<=(sharedCreature& creature) override;

    const std::type_info& getClass() const override;
}; // class Enemy


template<MovementPolicy movement_policy, AttackPolicy attack_policy>
using sharedEnemy = std::shared_ptr<class Enemy<movement_policy, attack_policy>>;


template<MovementPolicy movement_policy, AttackPolicy attack_policy>
Enemy<movement_policy, attack_policy>::Enemy(Position2D position) {
    setInteractionStrategy(std::make_shared<InteractionNone>());
    setPosition(position);
}


template<MovementPolicy movement_policy, AttackPolicy attack_policy>
Enemy<movement_policy, attack_policy>::~Enemy() {
    getEventManager().notify("Destroying: Object of class 'Enemy'.");
}


template<MovementPolicy movement_policy, AttackPolicy attack_policy>
void Enemy<movement_policy, attack_policy>::operator<=(sharedObject& object) {
    if (object_interaction_strategy_ != nullptr) {
        if (object != nullptr) {
            std::ostringstream ss;
            ss << "Object of class 'Enemy' interact with object of class '" << object->getClass().name() << "'";
            getEventManager().notify(ss);
        }

        object_interaction_strategy_->interact(*this, object);
    }
}


template<MovementPolicy movement_policy, AttackPolicy attack_policy>
void Enemy<movement_policy, attack_policy>::operator<=(sharedCreature& creature) {
    if (creature != nullptr) {
        std::ostringstream ss;
        ss << "Object of class 'Enemy' attack creature of class '" << creature->getClass().name() << "'\n";
        getEventManager().notify(ss);
        Creature::operator<=(creature);
    }
}


template<MovementPolicy movement_policy, AttackPolicy attack_policy>
const std::type_info& Enemy<movement_policy, attack_policy>::getClass() const {
    return typeid(Enemy);
}


#endif // SOURCES_GAME_OBJECTS_CREATURES_ENEMY_ENEMY_H
