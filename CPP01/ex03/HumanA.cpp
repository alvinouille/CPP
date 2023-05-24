#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA()
{

}

HumanA::HumanA(std::string nom, Weapon &weap)
{
    name = nom;
    weapon = weap.getType();
}

HumanA::~HumanA()
{

}

void    HumanA::attack()
{
    std::cout << name << "attacks with their " << weapon << std::endl;
}