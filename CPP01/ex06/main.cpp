#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;

    if (ac != 2)
    {
        std::cout << "ERROR : False number of arguments" << std::endl;
        return (1);
    }
    std::string level(av[1]);
    harl.complain(level);
}