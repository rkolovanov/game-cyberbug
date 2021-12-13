#include "sources/game/objects/medicines/medicinesfactory.h"

namespace game {


game::sharedObject game::MedicinesFactory::createObject() {
    return std::make_shared<Medicines>(20);
}


game::sharedObject game::MedicinesFactory::createMedicines(int healthRecovery) {
    return std::make_shared<Medicines>(healthRecovery);
}


};
