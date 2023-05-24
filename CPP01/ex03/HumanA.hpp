#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
    public:
        HumanA(void);
        HumanA(std::string nom, Weapon &weap);
        ~HumanA(void);
        void    attack(void);

    private:
        std::string name;
        std::string weapon;
} ;

#endif