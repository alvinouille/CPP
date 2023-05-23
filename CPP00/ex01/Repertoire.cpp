#include "Contact.hpp"
#include "Repertoire.hpp"

Repertoire::Repertoire()
{
    // std::cout << "Object Repertoire created" << std::endl;
}

Repertoire::~Repertoire()
{
    // std::cout << "Object Repertoire destroyed" << std::endl;
}

void    Repertoire::add_contact(int i)
{
    if (i > 7)
        i = 7 % (i - 7);
    tab[i].att();
}

Contact Repertoire::get(int i)
{
    return (tab[i]);
}

void    Repertoire::print(int max)
{
    int i;

    if (max > 7)
        max = 7;
    for (i = 0 ; i <= max ; i++)
        tab[i].print(i, 0);
}