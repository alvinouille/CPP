#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
    this->type = str;
}

Weapon::~Weapon()
{

}

const std::string &Weapon::getType(void)
{
    std::string &refType(type);

    return (refType);
}

void  Weapon::setType(const std::string str)
{
    this->type = str;
}