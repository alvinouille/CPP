#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string nom)
{
    name = nom;
    weapon = "";
}

HumanB::~HumanB()
{

}

void    HumanB::setWeapon(Weapon &weap)
{
    weapon = weap.getType();
}

void    HumanB::attack()
{
    std::cout << name << "attacks with their " << weapon << std::endl;
}