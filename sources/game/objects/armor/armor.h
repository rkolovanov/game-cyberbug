#ifndef SOURCES_GAME_OBJECTS_ARMOR_ARMOR_H
#define SOURCES_GAME_OBJECTS_ARMOR_ARMOR_H

#include "sources/game/objects/object.h"

using sharedArmor = std::shared_ptr<class Armor>;


class Armor final: public Object {
private:
    int protection_value_;

public:
    explicit Armor(int protection_value);
    ~Armor();

    friend std::ostream& operator<<(std::ostream& stream, const Armor& armor);

    sharedObject getCopy() const override;
    void executeInteraction(Creature& creature) override;
    const std::type_info& getClass() const override;
    bool getReusable() const override;
}; // class Armor


#endif // SOURCES_GAME_OBJECTS_ARMOR_ARMOR_H
