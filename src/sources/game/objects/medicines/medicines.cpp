#include <sstream>

#include "sources/game/objects/medicines/medicines.h"
#include "sources/game/objects/medicines/medicinesfactory.h"
#include "sources/game/creatures/creature.h"

namespace game {


game::Medicines::Medicines(int healthRecovery): health_recovery_(healthRecovery) {}


game::sharedObject game::Medicines::getCopy() const {
    return sharedObject(std::make_shared<MedicinesFactory>()->createMedicines(health_recovery_));
}


void game::Medicines::executeInteraction(Creature& creature) {
    creature.setHealth(creature.getHealth() + health_recovery_);
}


const std::type_info& game::Medicines::getClass() const {
    return typeid(Medicines);
}


bool game::Medicines::getReusable() const {
    return false;
}


game::Medicines::~Medicines() {
    std::ostringstream ss;
    ss << "Destroying: " << *this;
    getEventManager().notify(ss);
}


int game::Medicines::getHealthRecovery() const {
    return health_recovery_;
}


std::ostream& operator<<(std::ostream& stream, const Medicines& medicines) {
    stream << "Object of class 'Medicines': HealthRecovery(" << medicines.health_recovery_ << ")";
    return stream;
}


};
