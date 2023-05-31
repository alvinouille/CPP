#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string nom)
{
    name = nom;
}

HumanB::~HumanB()
{

}

void    HumanB::setWeapon(Weapon &weap)
{
    this->weapon = &weap;
}

void    HumanB::attack()
{
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}