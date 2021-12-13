#ifndef SOURCES_GAME_OBJECTS_MEDICINES_MEDICINES_H
#define SOURCES_GAME_OBJECTS_MEDICINES_MEDICINES_H

#include "sources/game/objects/object.h"

namespace game {

using sharedMedicines = std::shared_ptr<class Medicines>;


class Medicines final: public Object {
private:
    int health_recovery_;

public:
    explicit Medicines(int health_recovery);
    ~Medicines();

    friend std::ostream& operator<<(std::ostream& stream, const Medicines& medicines);

    int getHealthRecovery() const;
    sharedObject getCopy() const override;
    void executeInteraction(Creature& creature) override;
    const std::type_info& getClass() const override;
    bool getReusable() const override;
}; // class Mediciness


};

#endif // SOURCES_GAME_OBJECTS_MEDICINES_MEDICINES_H
