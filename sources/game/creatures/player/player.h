#ifndef SOURCES_GAME_OBJECTS_CREATURES_PLAYER_PLAYER_H
#define SOURCES_GAME_OBJECTS_CREATURES_PLAYER_PLAYER_H

#include <memory>

#include "sources/game/creatures/creature.h"
#include "sources/game/creatures/player/playermemento.h"

namespace game {

using sharedPlayer = std::shared_ptr<class Player>;
using sharedConstPlayer = std::shared_ptr<const class Player>;


class Player final: public Creature {
private:
    bool pass_founded_ = false;

public:
    explicit Player(Position2D position);
    ~Player() override;

    void operator<=(sharedObject& object) override;
    void operator<=(sharedCreature& creature) override;
    friend std::ostream& operator<<(std::ostream& stream, const Player& player);

    const std::type_info& getClass() const override;
    virtual void setRotation(Rotation rotation) override;
    virtual void setPosition(Position2D position) override;
    virtual void setHealth(int health) override;
    virtual void setMaxHealth(int maxHealth) override;
    virtual void setAttackDamage(int damage) override;
    virtual void setProtection(int protection) override;
    bool getPassFounded() const;
    void setPassFounded(bool value);
    PlayerMemento save() const;
    void restore(const PlayerMemento& snapshot);
}; // class Player


};

#endif // SOURCES_GAME_OBJECTS_CREATURES_PLAYER_PLAYER_H
