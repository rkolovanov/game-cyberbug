#ifndef SOURCES_GAME_OBJECTS_CREATURE_PLAYER_PLAYER_MEMENTO_H
#define SOURCES_GAME_OBJECTS_CREATURE_PLAYER_PLAYER_MEMENTO_H

#include "sources/common/imemento.h"
#include "sources/game/creatures/creature.h"
#include "sources/game/interactions/interactiontype.h"

namespace game {


class PlayerMemento final: public IMemento {
private:
    int health_;
    int max_health_;
    int attack_damage_;
    int protection_;
    Position2D position_;
    Rotation rotation_;
    InteractionType interaction_type_;
    bool pass_founded_;

public:
    PlayerMemento() = default;
    PlayerMemento(int health, int max_health, int damage, int protection, Position2D position,
                  Rotation rotation, InteractionType interaction_type, bool pass_founded);
    int getHealth() const;
    int getMaxHealth() const;
    int getAttackDamage() const;
    int getProtection() const;
    Position2D getPosition() const;
    Rotation getRotation() const;
    InteractionType getInteractionType() const;
    bool getPassFounded() const;
}; // class PlayerMemento


};

#endif // SOURCES_GAME_OBJECTS_CREATURE_PLAYER_PLAYER_MEMENTO_H
