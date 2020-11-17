#include "medicines.h"
#include "medicinesfactory.h"
#include <sstream>

Medicines::Medicines(int healthRecovery): healthRecovery_(healthRecovery) {}

pObject Medicines::getCopy() const {
    pMedicinesFactory factory(new MedicinesFactory);
    return pObject(factory->createMedicines(healthRecovery_));
}

void Medicines::executeInteraction(Creature& creature) {
    creature.setHealth(creature.getHealth() + healthRecovery_);
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
    stream << "Object of class 'Medicines': HealthRecovery(" << medicines.healthRecovery_ << ")\n";
    return stream;
}
