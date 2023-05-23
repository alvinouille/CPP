#include "Contact.hpp"

#ifndef REPERTOIRE_HPP
# define REPERTOIRE_HPP

#include <string>
#include <iostream>

class Repertoire
{
    public:
        Repertoire();
        ~Repertoire();
        void    print(int max);
        void    add_contact(int i);
        Contact get(int i);

    private:
        Contact tab[8];
};

#endif