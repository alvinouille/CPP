#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string str, Weapon &weap) : name(str), weapon(weap)
{}

HumanA::~HumanA()
{}

void    HumanA::attack()
{
    std::cout << name << " attacks with their " << this->weapon.getType() << std::endl;
}