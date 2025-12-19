// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#include "transformer.h"

namespace tf
{

Transformer::Transformer()
    : _level(0), _strength(0), _fuel(0), _weapon(Weapon(10, 10)), _pilot(nullptr)
{
}

Transformer::Transformer(unsigned int level, unsigned int strength, unsigned int fuel, const Weapon& weapon)
    : _level(level), _strength(strength), _fuel(fuel), _weapon(weapon), _pilot(nullptr)
{
}

Transformer::~Transformer()
{
}

void Transformer::setPilot(Pilot* pilot)
{
    _pilot = pilot;
}

Pilot* Transformer::getPilot() const
{
    return _pilot;
}

unsigned int Transformer::getLevel() const
{
    return _level;
}

unsigned int Transformer::getStrength() const
{
    return _strength;
}

unsigned int Transformer::getFuel() const
{
    return _fuel;
}

bool Transformer::move()
{
    std::cout << "Transformer::move()" << std::endl;
    return true;
}

bool Transformer::jump()
{
    std::cout << "Transformer::jump()" << std::endl;
    return true;
}

bool Transformer::fire()
{
    std::cout << "Transformer::fire()" << std::endl;
    _weapon.fire();
    return true;
}

void Transformer::openFire()
{
    std::cout << "Transformer::openFire()" << std::endl;
    _weapon.fire();
}

void Transformer::ultraMove()
{
    std::cout << "Transformer::ultraMove()" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Transformer& t)
{
    os << "Transformer(Level: " << t._level
       << ", Strength: " << t._strength
       << ", Fuel: " << t._fuel << ")";
    return os;
}

void Transformer::setLevel(unsigned int level)
{
    _level = level;
}

void Transformer::setStrength(unsigned int strength)
{
    _strength = strength;
}

void Transformer::setFuel(unsigned int fuel)
{
    _fuel = fuel;
}

Weapon& Transformer::getWeapon()
{
    return _weapon;
}

const Weapon& Transformer::getWeapon() const
{
    return _weapon;
}

} // namespace tf
