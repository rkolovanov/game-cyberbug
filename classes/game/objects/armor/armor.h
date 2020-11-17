#ifndef ARMOR_H
#define ARMOR_H

#include "classes/game/objects/object.h"

typedef std::shared_ptr<class Armor> pArmor;


class Armor: public Object {
private:
    int protectionValue_;

public:
    explicit Armor(int protectionValue);
    pObject getCopy() const;
    void executeInteraction(Creature& creature);
    const std::type_info& getClass() const;
    bool getReusable() const;
    ~Armor();

    friend std::ostream& operator<<(std::ostream& stream, const Armor& armor);
};


#endif // ARMOR_H
