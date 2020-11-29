#include "sources/game/objects/medicines/medicinesfactory.h"


sharedObject MedicinesFactory::createObject() {
    return std::make_shared<Medicines>(20);
}


sharedObject MedicinesFactory::createMedicines(int healthRecovery) {
    return std::make_shared<Medicines>(healthRecovery);
}
