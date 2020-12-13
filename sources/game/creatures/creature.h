#ifndef SOURCES_GAME_OBJECTS_CREATURES_CREATURE_H
#define SOURCES_GAME_OBJECTS_CREATURES_CREATURE_H

#include <memory>

#include "sources/game/objects/object.h"
#include "sources/common/point2d.h"
#include "sources/common/direction.h"
#include "sources/game/interactions/interactionstrategy.h"
#include "sources/common/eventmanager.h"

namespace game {

using sharedObject = std::shared_ptr<class Object>;
using sharedCreature = std::shared_ptr<class Creature>;
using sharedConstCreature = std::shared_ptr<const class Creature>;


class Creature {
protected:
    int health_;
    int max_health_;
    int attack_damage_;
    int protection_;
    Position2D position_;
    Rotation rotation_ = Direction::Bottom;
    EventManager event_manager_;
    sharedInteractionStrategy object_interaction_strategy_;

public:
    virtual ~Creature() = default;
    virtual void operator<=(sharedObject& object) = 0;
    virtual void operator<=(sharedCreature& creature) = 0;
    virtual const std::type_info& getClass() const = 0;

    EventManager& getEventManager();
    Rotation getRotation() const;
    Position2D getPosition() const;
    int getHealth() const;
    int getMaxHealth() const;
    int getAttackDamage() const;
    int getProtection() const;
    virtual void setRotation(Rotation rotation);
    virtual void setPosition(Position2D position);
    virtual void setHealth(int health);
    virtual void setMaxHealth(int maxHealth);
    virtual void setAttackDamage(int damage);
    virtual void setProtection(int protection);
    void setInteractionStrategy(const sharedInteractionStrategy& objectInteractionStrategy);
}; // class Creature


};

#endif // SOURCES_GAME_OBJECTS_CREATURES_CREATURE_H
