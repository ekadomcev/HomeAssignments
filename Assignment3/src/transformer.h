// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "weapon.h"
#include "pilot.h"
#include <iostream>

namespace tf
{

class Transformer
{
public:
    // Constructor overloading
    Transformer();
    Transformer(unsigned int level, unsigned int strength, unsigned int fuel, const Weapon& weapon);
    virtual ~Transformer();

    // Non-copyable (Pilot* association could lead to confusion if copied)
    Transformer(const Transformer&) = delete;
    Transformer& operator=(const Transformer&) = delete;

    void setPilot(Pilot* pilot);
    Pilot* getPilot() const;

    unsigned int getLevel() const;
    unsigned int getStrength() const;
    unsigned int getFuel() const;

    // Virtual methods (each prints class name and method name)
    virtual bool move();
    virtual bool jump();
    virtual bool fire();

    // Pure virtual method - must be overridden
    virtual void transform() = 0;

    // Additional virtual methods for polymorphism demo
    virtual void openFire();
    virtual void ultraMove();

    // Operator overloading for output
    friend std::ostream& operator<<(std::ostream& os, const Transformer& t);

protected:
    // Protected accessors for derived classes
    void setLevel(unsigned int level);
    void setStrength(unsigned int strength);
    void setFuel(unsigned int fuel);
    Weapon& getWeapon();
    const Weapon& getWeapon() const;

private:
    unsigned int _level;
    unsigned int _strength;
    unsigned int _fuel;
    Weapon _weapon;
    Pilot* _pilot;
};

} // namespace tf

#endif
