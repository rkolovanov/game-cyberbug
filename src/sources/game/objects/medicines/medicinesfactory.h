#ifndef SOURCES_GAME_OBJECTS_MEDICINES_MEDICINES_FACTORY_H
#define SOURCES_GAME_OBJECTS_MEDICINES_MEDICINES_FACTORY_H

#include "sources/game/objects/objectfactory.h"
#include "sources/game/objects/medicines/medicines.h"

namespace game {

using sharedMedicinesFactory = std::shared_ptr<class MedicinesFactory>;


class MedicinesFactory final: public ObjectFactory {
public:
    virtual sharedObject createObject() override;
    virtual sharedObject createMedicines(int health_recovery);
}; // class MedicinesFactory


};

#endif // SOURCES_GAME_OBJECTS_MEDICINES_MEDICINES_FACTORY_H
