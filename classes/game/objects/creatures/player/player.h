#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include "classes/game/objects/creatures/creature.h"

typedef std::shared_ptr<class Player> pPlayer;
typedef std::shared_ptr<const class Player> pConstPlayer;


class Player: public Creature {
private:
    bool passFounded_ = false;
    pInteractionStrategy objectInteractionStrategy_;

public:
    Player(Position2D position);
    const std::type_info& getClass() const;
    void operator<=(pObject& object);
    bool getPassFounded() const;
    void setPassFounded(bool value);
    void changeInteraction(pInteractionStrategy objectInteractionStrategy);
    virtual void setRotation(Rotation rotation);
    virtual void setPosition(Position2D position);
    virtual void setHealth(int health);
    virtual void setMaxHealth(int maxHealth);
    virtual void setAttackDamage(int damage);
    virtual void setProtection(int protection);

    friend std::ostream& operator<<(std::ostream& stream, const Player& player);
};


#endif // PLAYER_H
