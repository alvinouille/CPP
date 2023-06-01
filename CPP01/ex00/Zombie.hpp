#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    public:
        Zombie(void);
        ~Zombie(void);
        void announce(void);
        void    set_name(std::string name);

    private:
        std::string name;
} ;

#endif
