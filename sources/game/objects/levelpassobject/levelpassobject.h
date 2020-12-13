#ifndef SOURCES_GAME_OBJECTS_LEVEL_PASS_OBJECT_LEVEL_PASS_OBJECT_H
#define SOURCES_GAME_OBJECTS_LEVEL_PASS_OBJECT_LEVEL_PASS_OBJECT_H

#include "sources/game/objects/object.h"

namespace game {


class LevelPassObject final: public Object {
public:
    ~LevelPassObject();

    friend std::ostream& operator<<(std::ostream& stream, const LevelPassObject& levelPassObject);

    sharedObject getCopy() const override;
    const std::type_info& getClass() const override;
    void executeInteraction(Creature& creature) override;
    bool getReusable() const override;
}; // class LevelPassObject


};

#endif // SOURCES_GAME_OBJECTS_LEVEL_PASS_OBJECT_LEVEL_PASS_OBJECT_H
