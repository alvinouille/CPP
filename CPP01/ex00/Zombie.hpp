#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    public:
        Zombie(void);
        Zombie(std::string str);
        ~Zombie(void);
        void announce(void);

    private:
        std::string name;
} ;

#endif