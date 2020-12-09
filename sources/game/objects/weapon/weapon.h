#ifndef SOURCES_GAME_OBJECTS_WEAPON_WEAPON_H
#define SOURCES_GAME_OBJECTS_WEAPON_WEAPON_H

#include "sources/game/objects/object.h"

using sharedArmor = std::shared_ptr<class Armor>;


class Weapon final: public Object {
private:
    int damage_;

public:
    explicit Weapon(int damage);
    ~Weapon();

    friend std::ostream& operator<<(std::ostream& stream, const Weapon& weapon);

    int getDamage() const;
    sharedObject getCopy() const override;
    void executeInteraction(Creature& creature) override;
    const std::type_info& getClass() const override;
    bool getReusable() const override;
}; // class Weapon


#endif // SOURCES_GAME_OBJECTS_WEAPON_WEAPON_H
