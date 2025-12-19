// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#include <iostream>
#include "autobot.h"
#include "decepticon.h"
#include "minicon.h"

int main()
{
    tf::Weapon cannon(50, 10);
    tf::Autobot prime(10, 500, 300, cannon, 100, true);
    tf::Decepticon megatron(10, 510, 290, cannon, 100, false);
    tf::MiniCon spark(1, 20, 10, cannon, 1, false);

    std::cout << "=== Transformers Demo ===" << std::endl;
    std::cout << prime << std::endl;
    std::cout << megatron << std::endl;
    std::cout << spark << std::endl;

    std::cout << "\n=== Transform ===" << std::endl;
    prime.transform();
    megatron.transform();
    spark.transform();

    std::cout << "\n=== Virtual method via base pointer ===" << std::endl;
    tf::Transformer* bot = &prime;
    bot->openFire();
    bot->ultraMove();

    return 0;
}
