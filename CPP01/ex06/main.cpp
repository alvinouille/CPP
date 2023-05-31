#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    std::string level(av[1]);

    harl.complain(level);
}