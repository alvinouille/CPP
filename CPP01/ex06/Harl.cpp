#include "Harl.hpp"

Harl::Harl()
{
    tab[0] = &Harl::debug;
    tab[1] = &Harl::info;
    tab[2] = &Harl::warning;
    tab[3] = &Harl::error;
}

Harl::~Harl()
{
    
}

void    Harl::debug()
{
    std::cout << "DEBUG : I love having extra bacon for my 7XL-double-cheese-triple-";
    std::cout << "pickle-special-ketchup burger. I really do !" << std::endl;
}

void    Harl::info()
{
    std::cout << "INFO : I cannot believe adding extra bacon costs more money. You didn’t put enough bacon"; 
    std::cout << "in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void    Harl::warning()
{
    std::cout << "WARNING : I think I deserve to have some extra bacon for free. I’ve been coming";
    std::cout << "for years whereas you started working here since last month." << std::endl;
}

void    Harl::error()
{
    std::cout << "ERROR : This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i(0);

    for(i = 0 ; i < 4 ; i++)
    {
        if (levels[i] == level)
        {
            switch (i)
            {
                case 0:
                    Harl::debug();
                case 1:
                    Harl::info();
                case 2:
                    Harl::warning();
                case 3:
                    Harl::error();
            }
        }
    }
}