// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#include "decepticon.h"

namespace tf
{

Decepticon::Decepticon()
    : Transformer(), _malice(0), _stealthMode(false)
{
}

Decepticon::Decepticon(unsigned int level, unsigned int strength, unsigned int fuel, const Weapon& weapon, unsigned int malice, bool stealthMode)
    : Transformer(level, strength, fuel, weapon), _malice(malice), _stealthMode(stealthMode)
{
}

unsigned int Decepticon::getMalice() const
{
    return _malice;
}

bool Decepticon::isStealthMode() const
{
    return _stealthMode;
}

void Decepticon::scheme()
{
    std::cout << "Decepticon::scheme()" << std::endl;
}

void Decepticon::transform()
{
    std::cout << "Decepticon::transform() - transforming into a jet!" << std::endl;
}

void Decepticon::openFire()
{
    std::cout << "Decepticon::openFire() - shooting missiles!" << std::endl;
    getWeapon().fire();
}

void Decepticon::ultraMove()
{
    std::cout << "Decepticon::ultraMove() - warp speed!" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Decepticon& d)
{
    os << "Decepticon(Level: " << d.getLevel()
       << ", Malice: " << d._malice << ")";
    return os;
}

} // namespace tf
