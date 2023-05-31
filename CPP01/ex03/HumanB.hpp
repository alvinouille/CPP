#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
    public:
        HumanB(std::string nom);
        ~HumanB(void);
        void    attack(void);
        void    setWeapon(Weapon &weap);

    private:
        std::string name;
        Weapon      *weapon;
} ;

#endif