#include "player.h"
#include "classes/game/interaction/interactionuse.h"
#include "classes/game/interaction/interactionnone.h"
#include <sstream>

Player::Player(Position2D position) {
    objectInteractionStrategy_ = pInteractionStrategy(new InteractionUse);
    setPosition(position);
}

const std::type_info &Player::getClass() const {
    return typeid(Player);
}

void Player::operator<=(pObject& object) {
    if (objectInteractionStrategy_ != nullptr) {
        if (object != nullptr) {
            std::ostringstream ss;
            ss << "Object of class 'Player' interact with object of class '" << object->getClass().name() << "'\n";
            getEventManager().notify(ss);
        }
        objectInteractionStrategy_->interact(*this, object);
    }
}

bool Player::getPassFounded() const {
    return passFounded_;
}

void Player::setPassFounded(bool value) {
    passFounded_ = value;
}

void Player::changeInteraction(pInteractionStrategy objectInteractionStrategy) {
    objectInteractionStrategy_ = objectInteractionStrategy;
}

void Player::setRotation(Rotation rotation) {
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

        getEventManager().notify("Object of class 'Player' change rotation to '" + directionName + "'\n");
    }
}

void Player::setPosition(Position2D position) {
    if (position != getPosition()) {
        Creature::setPosition(position);
        std::ostringstream ss;
        ss << "Object of class 'Player' change position to [" << getPosition().x << ", " << getPosition().y << "]\n";
        getEventManager().notify(ss);
    }
}

void Player::setHealth(int health) {
    if (health != getHealth()) {
        Creature::setHealth(health);
        std::ostringstream ss;
        ss << "Object of class 'Player' change health to " << getHealth() << "\n";
        getEventManager().notify(ss);
    }
}

void Player::setMaxHealth(int maxHealth) {
    if (maxHealth != getMaxHealth()) {
        Creature::setMaxHealth(maxHealth);
        std::ostringstream ss;
        ss << "Object of class 'Player' change maximum health to " << getMaxHealth() << "\n";
        getEventManager().notify(ss);
    }
}

void Player::setAttackDamage(int damage) {
    if (damage != getAttackDamage()) {
        Creature::setAttackDamage(damage);
        std::ostringstream ss;
        ss << "Object of class 'Player' change attack damage to " << getAttackDamage() << "\n";
        getEventManager().notify(ss);
    }
}

void Player::setProtection(int protection) {
    if (protection != getProtection()) {
        Creature::setProtection(protection);
        std::ostringstream ss;
        ss << "Object of class 'Player' change protection to " << getProtection() << "\n";
        getEventManager().notify(ss);
    }
}

std::ostream& operator<<(std::ostream& stream, const Player& player) {
    stream << "Object of class 'Player': Position(" << player.getPosition() << "); Health(" << player.getHealth() << "); MaxHealth("
           << player.getMaxHealth() << "); AttackDamage(" << player.getAttackDamage() << "); Protection(" << player.getProtection()
           << "); Rotation(" << (int)(player.getRotation()) << "); PassFounded(" << player.getPassFounded() << ")\n";
    return stream;
}
