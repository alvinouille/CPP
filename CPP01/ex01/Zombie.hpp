#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    public:
        Zombie(void);
        ~Zombie(void);
        void    set_name(std::string str);
        void    announce(void);

    private:
        std::string name;
} ;

#endif
