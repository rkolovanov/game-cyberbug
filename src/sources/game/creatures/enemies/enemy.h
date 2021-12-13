#ifndef SOURCES_GAME_OBJECTS_CREATURES_ENEMIES_ENEMY_H
#define SOURCES_GAME_OBJECTS_CREATURES_ENEMIES_ENEMY_H

#include <memory>

#include "sources/game/creatures/enemies/abstractenemy.h"
#include "sources/game/creatures/meleeattackbehavior.h"
#include "sources/game/creatures/distanceattackbehavior.h"
#include "sources/game/creatures/standmovementbehavior.h"
#include "sources/game/creatures/walkmovementbehavior.h"
#include "sources/game/interactions/interactionnone.h"

namespace game {


template<typename movement_behavior, typename attack_behavior>
class Enemy final: public AbstractEnemy {
private:
    sharedMovementBehavior movement_behavior_;
    sharedAttackBehavior attack_behavior_;

public:
    explicit Enemy(Position2D position);
    ~Enemy() override;

    void operator<=(sharedObject& object) override;
    void operator<=(sharedCreature& creature) override;

    Position2D getMovementPosition(const Position2D& target_position) override;
    void tryAttack(sharedCreature& target) override;
    const std::type_info& getClass() const override;
    EnemyMemento save() const;
    void restore(const EnemyMemento& snapshot);
}; // class Enemy


template<typename movement_behavior, typename attack_behavior>
using sharedEnemy = std::shared_ptr<class Enemy<movement_behavior, attack_behavior>>;


template<typename movement_behavior, typename attack_behavior>
Enemy<movement_behavior, attack_behavior>::Enemy(Position2D position) {
    setInteractionStrategy(std::make_shared<InteractionNone>());
    setPosition(position);
    movement_behavior_ = std::make_shared<movement_behavior>();
    attack_behavior_ = std::make_shared<attack_behavior>();
}


template<typename movement_behavior, typename attack_behavior>
Enemy<movement_behavior, attack_behavior>::~Enemy() {
    getEventManager().notify("Destroying: Object of class 'Enemy'.");
}


template<typename movement_behavior, typename attack_behavior>
void Enemy<movement_behavior, attack_behavior>::operator<=(sharedObject& object) {
    if (object_interaction_strategy_ != nullptr) {
        if (object != nullptr) {
            std::ostringstream ss;
            ss << "Object of class 'Enemy' interact with object of class '" << object->getClass().name() << "'";
            getEventManager().notify(ss);
        }
        object_interaction_strategy_->interact(*this, object);
    }
}


template<typename movement_behavior, typename attack_behavior>
void Enemy<movement_behavior, attack_behavior>::operator<=(sharedCreature& creature) {
    if (creature != nullptr) {
        std::ostringstream ss;
        ss << "Object of class 'Enemy' attack creature of class '" << creature->getClass().name() << "'";
        getEventManager().notify(ss);
        Creature::operator<=(creature);
    }
}


template<typename movement_behavior, typename attack_behavior>
Position2D Enemy<movement_behavior, attack_behavior>::getMovementPosition(const Position2D& target_position) {
    return movement_behavior_->getMovementPosition(*this, target_position);
}


template<typename movement_behavior, typename attack_behavior>
void Enemy<movement_behavior, attack_behavior>::tryAttack(sharedCreature& target) {
    attack_behavior_->attack(*this, target);
}


template<typename movement_behavior, typename attack_behavior>
const std::type_info& Enemy<movement_behavior, attack_behavior>::getClass() const {
    return typeid(Enemy);
}


template<typename movement_behavior, typename attack_behavior>
EnemyMemento Enemy<movement_behavior, attack_behavior>::save() const {
    return EnemyMemento(health_, max_health_, attack_damage_, protection_, position_, rotation_,
                        typeid(movement_behavior).hash_code(), typeid(attack_behavior).hash_code());
}


template<typename movement_behavior, typename attack_behavior>
void Enemy<movement_behavior, attack_behavior>::restore(const EnemyMemento& snapshot) {
    setMaxHealth(snapshot.getMaxHealth());
    setHealth(snapshot.getHealth());
    setAttackDamage(snapshot.getAttackDamage());
    setProtection(snapshot.getProtection());
    setPosition(snapshot.getPosition());
    setRotation(snapshot.getRotation());
}


};

#endif // SOURCES_GAME_OBJECTS_CREATURES_ENEMIES_ENEMY_H
