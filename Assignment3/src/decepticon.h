// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "transformer.h"
#include <iostream>

namespace tf
{

class Decepticon : public Transformer
{
public:
    // Constructor overloading
    Decepticon();
    Decepticon(unsigned int level, unsigned int strength, unsigned int fuel, const Weapon& weapon, unsigned int malice, bool stealthMode);

    unsigned int getMalice() const;
    bool isStealthMode() const;
    void scheme();

    // Overrides (virtual methods that print class::method)
    void transform() override;
    void openFire() override;
    void ultraMove() override;

    // Operator overloading for output
    friend std::ostream& operator<<(std::ostream& os, const Decepticon& d);

private:
    unsigned int _malice;
    bool _stealthMode;
};

} // namespace tf

#endif
