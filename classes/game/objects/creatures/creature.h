#ifndef CREATURE_H
#define CREATURE_H

#include <memory>
#include "classes/game/objects/object.h"
#include "classes/common/point2d.h"
#include "classes/enumerations/direction.h"
#include "classes/enumerations/texture.h"
#include "classes/game/interaction/interactionstrategy.h"
#include "classes/common/eventmanager.h"

typedef std::shared_ptr<class Creature> pCreature;
typedef std::shared_ptr<const class Creature> pConstCreature;
typedef std::shared_ptr<class Object> pObject;


class Creature {
private:
    int health_;
    int maxHealth_;
    int attackDamage_;
    int protection_;
    Position2D position_;
    Rotation rotation_ = Direction::Bottom;
    EventManager eventManager_;

public:
    virtual void operator<=(pObject& object) = 0;
    virtual const std::type_info& getClass() const = 0;
    virtual ~Creature() = default;

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
};


#endif // CREATURE_H
