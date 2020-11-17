#include "medicinesfactory.h"

pObject MedicinesFactory::createObject() {
    return pObject(new Medicines(20));
}

pObject MedicinesFactory::createMedicines(int healthRecovery) {
    return pObject(new Medicines(healthRecovery));
}
