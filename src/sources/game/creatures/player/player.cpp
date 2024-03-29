#include <sstream>

#include "sources/game/creatures/player/player.h"
#include "sources/game/interactions/interactionuse.h"
#include "sources/game/interactions/interactionnone.h"

namespace game {


game::Player::Player(Position2D position) {
    setInteractionStrategy(std::make_shared<InteractionUse>());
    setPosition(position);
}

game::Player::~Player() {
    std::ostringstream ss;
    ss << "Destroying: " << *this;
    getEventManager().notify(ss);
}


const std::type_info& game::Player::getClass() const {
    return typeid(Player);
}


void game::Player::operator<=(sharedObject& object) {
    if (object_interaction_strategy_ != nullptr) {
        if (object != nullptr) {
            std::ostringstream ss;
            ss << "Object of class 'Player' interact with object of class '" << object->getClass().name() << "'";
            getEventManager().notify(ss);
        }

        object_interaction_strategy_->interact(*this, object);
    }
}

void game::Player::operator<=(sharedCreature& creature) {
    if (creature != nullptr) {
        std::ostringstream ss;
        ss << "Object of class 'Player' attack creature of class '" << creature->getClass().name() << "'";
        getEventManager().notify(ss);
        Creature::operator<=(creature);
    }
}


bool game::Player::getPassFounded() const {
    return pass_founded_;
}


void game::Player::setPassFounded(bool value) {
    pass_founded_ = value;
}


game::PlayerMemento game::Player::save() const {
    return PlayerMemento(health_, max_health_, attack_damage_, protection_, position_, rotation_,
                         object_interaction_strategy_->getType(), pass_founded_);
}


void game::Player::restore(const PlayerMemento& snapshot) {
    setHealth(snapshot.getHealth());
    setMaxHealth(snapshot.getMaxHealth());
    setAttackDamage(snapshot.getAttackDamage());
    setProtection(snapshot.getProtection());
    setPassFounded(snapshot.getPassFounded());
    setPosition(snapshot.getPosition());
    setRotation(snapshot.getRotation());

    if (snapshot.getInteractionType() == InteractionType::None) {
        object_interaction_strategy_ = std::make_shared<InteractionNone>();
    } else if (snapshot.getInteractionType() == InteractionType::Use) {
        object_interaction_strategy_ = std::make_shared<InteractionUse>();
    }
}


void game::Player::setRotation(Rotation rotation) {
    if (rotation != getRotation()) {
        Creature::setRotation(rotation);
        std::string directionName;

        switch (rotation) {
        case Direction::Top:
            directionName = "Top";
            break;
        case Direction::Bottom:
            directionName = "Bottom";
            break;
        case Direction::Left:
            directionName = "Left";
            break;
        case Direction::Right:
            directionName = "Right";
            break;
        };

        getEventManager().notify("Object of class 'Player' change rotation to '" + directionName + "'");
    }
}


void game::Player::setPosition(Position2D position) {
    if (position != getPosition()) {
        Creature::setPosition(position);
        std::ostringstream ss;
        ss << "Object of class 'Player' change position to [" << getPosition().x << ", " << getPosition().y << "]";
        getEventManager().notify(ss);
    }
}


void game::Player::setHealth(int health) {
    if (health != getHealth()) {
        Creature::setHealth(health);
        std::ostringstream ss;
        ss << "Object of class 'Player' change health to " << getHealth();
        getEventManager().notify(ss);
    }
}


void game::Player::setMaxHealth(int maxHealth) {
    if (maxHealth != getMaxHealth()) {
        Creature::setMaxHealth(maxHealth);
        std::ostringstream ss;
        ss << "Object of class 'Player' change maximum health to " << getMaxHealth();
        getEventManager().notify(ss);
    }
}


void game::Player::setAttackDamage(int damage) {
    if (damage != getAttackDamage()) {
        Creature::setAttackDamage(damage);
        std::ostringstream ss;
        ss << "Object of class 'Player' change attack damage to " << getAttackDamage();
        getEventManager().notify(ss);
    }
}


void game::Player::setProtection(int protection) {
    if (protection != getProtection()) {
        Creature::setProtection(protection);
        std::ostringstream ss;
        ss << "Object of class 'Player' change protection to " << getProtection();
        getEventManager().notify(ss);
    }
}


std::ostream& operator<<(std::ostream& stream, const Player& player) {
    stream << "Object of class 'Player': Position(" << player.getPosition() << "); Health(" << player.getHealth() << "); MaxHealth("
           << player.getMaxHealth() << "); AttackDamage(" << player.getAttackDamage() << "); Protection(" << player.getProtection()
           << "); Rotation(" << (int)(player.getRotation()) << "); PassFounded(" << player.getPassFounded() << ")";
    return stream;
}


};
