#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::~Zombie()
{
    // std::cout << "Destruction of : " << name << std::endl;
}

void    Zombie::set_name(std::string str)
{
    this->name = str;
}

void    Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
