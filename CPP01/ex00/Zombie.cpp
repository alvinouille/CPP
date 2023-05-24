#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::Zombie(std::string str)
{
    name = str;
}

Zombie::~Zombie()
{
    std::cout << "Destruction of : " << name << std::endl;
}

void    Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
