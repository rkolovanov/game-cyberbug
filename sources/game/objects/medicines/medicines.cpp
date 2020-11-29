#include <sstream>

#include "sources/game/objects/medicines/medicines.h"
#include "sources/game/objects/medicines/medicinesfactory.h"
#include "sources/game/objects/creatures/creature.h"


Medicines::Medicines(int healthRecovery): health_recovery_(healthRecovery) {}


sharedObject Medicines::getCopy() const {
    return sharedObject(std::make_shared<MedicinesFactory>()->createMedicines(health_recovery_));
}


void Medicines::executeInteraction(Creature& creature) {
    creature.setHealth(creature.getHealth() + health_recovery_);
}


const std::type_info& Medicines::getClass() const {
    return typeid(Medicines);
}


bool Medicines::getReusable() const {
    return false;
}


Medicines::~Medicines() {
    std::ostringstream ss;
    ss << "Destroying: " << *this;
    getEventManager().notify(ss);
}


std::ostream& operator<<(std::ostream& stream, const Medicines& medicines) {
    stream << "Object of class 'Medicines': HealthRecovery(" << medicines.health_recovery_ << ")";
    return stream;
}
