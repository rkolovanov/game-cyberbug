#ifndef MEDICINES_H
#define MEDICINES_H

#include "classes/game/objects/object.h"

typedef std::shared_ptr<class Medicines> pMedicines;


class Medicines: public Object {
private:
    int healthRecovery_;

public:
    explicit Medicines(int healthRecovery);
    pObject getCopy() const;
    void executeInteraction(Creature& creature);
    const std::type_info& getClass() const;
    bool getReusable() const;
    ~Medicines();

    friend std::ostream& operator<<(std::ostream& stream, const Medicines& medicines);
};


#endif // MEDICINES_H
