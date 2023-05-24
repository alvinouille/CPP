#include "Zombie.h"

Zombie  *zombieHorde(int N, std::string name)
{
    Zombie *zombie;
    int     i;

    zombie = new Zombie[N];
    for (i = 0 ; i < N ; i++)
        zombie[i].set_name(name);
    return (zombie);
}