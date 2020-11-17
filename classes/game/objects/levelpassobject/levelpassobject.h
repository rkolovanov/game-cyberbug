#ifndef LEVEL_PASS_OBJECT_H
#define LEVEL_PASS_OBJECT_H

#include "classes/game/objects/object.h"


class LevelPassObject: public Object {
public:
    pObject getCopy() const;
    const std::type_info& getClass() const;
    void executeInteraction(Creature& creature);
    bool getReusable() const;
    ~LevelPassObject();

    friend std::ostream& operator<<(std::ostream& stream, const LevelPassObject& levelPassObject);
};


#endif // LEVEL_PASS_OBJECT_H
