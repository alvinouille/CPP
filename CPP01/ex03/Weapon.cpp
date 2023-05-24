#include "Weapon.hpp"

Weapon::Weapon()
{
    type = "";
}

Weapon::Weapon(std::string str)
{
    type = str;
}

Weapon::~Weapon()
{

}

std::string Weapon::getType(void)
{
    return (type);
}

void  Weapon::setType(const std::string &str)
{
    type = str;
}