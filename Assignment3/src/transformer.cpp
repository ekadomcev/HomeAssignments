// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#include "transformer.h"

Transformer::Transformer(unsigned int level, unsigned int strength, unsigned int fuel, const Weapon& weapon)
    : _level(level), _strength(strength), _fuel(fuel), _weapon(weapon), _pilot(nullptr) {}

Transformer::~Transformer() {}

void Transformer::setPilot(Pilot* pilot) {
    _pilot = pilot;
}

Pilot* Transformer::getPilot() const {
    return _pilot;
}

unsigned int Transformer::getLevel() const {
    return _level;
}

unsigned int Transformer::getStrength() const {
    return _strength;
}

unsigned int Transformer::getFuel() const {
    return _fuel;
}

bool Transformer::move() {
    return true;
}

bool Transformer::jump() {
    return true;
}

bool Transformer::transform() {
    return true;
}

bool Transformer::fire() {
    _weapon.fire();
    return true;
}
