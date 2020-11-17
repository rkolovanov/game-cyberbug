#ifndef WEAPON_H
#define WEAPON_H

#include "classes/game/objects/object.h"

typedef std::shared_ptr<class Armor> pArmor;


class Weapon: public Object {
private:
    int damage_;

public:
    explicit Weapon(int damage);
    pObject getCopy() const;
    void executeInteraction(Creature& creature);
    const std::type_info& getClass() const;
    bool getReusable() const;
    ~Weapon();

    friend std::ostream& operator<<(std::ostream& stream, const Weapon& weapon);
};


#endif // WEAPON_H
