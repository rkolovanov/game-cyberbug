#ifndef MEDICINES_FACTORY_H
#define MEDICINES_FACTORY_H

#include "classes/game/objects/objectfactory.h"
#include "classes/game/objects/medicines/medicines.h"

typedef std::shared_ptr<class MedicinesFactory> pMedicinesFactory;


class MedicinesFactory: public ObjectFactory {
public:
    virtual pObject createObject();
    virtual pObject createMedicines(int healthRecovery);
};


#endif // MEDICINES_FACTORY_H
