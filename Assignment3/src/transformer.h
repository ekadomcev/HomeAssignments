// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "weapon.h"
#include "pilot.h"

class Transformer {
public:
    Transformer(unsigned int level, unsigned int strength, unsigned int fuel, const Weapon& weapon);
    virtual ~Transformer();

    void setPilot(Pilot* pilot);
    Pilot* getPilot() const;

    unsigned int getLevel() const;
    unsigned int getStrength() const;
    unsigned int getFuel() const;
    
    // Actions
    bool move();
    bool jump();
    bool transform();
    bool fire();

protected:
    unsigned int _level;
    unsigned int _strength;
    unsigned int _fuel;
    Weapon _weapon;
    Pilot* _pilot;
};

#endif
