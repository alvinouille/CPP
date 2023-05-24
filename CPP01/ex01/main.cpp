#include "Zombie.h"

int main()
{
    Zombie *zombie;
    int N(10);
    int i(0);

    zombie = zombieHorde(N, "Alfred");
    for (i = 0 ; i < N ; i++)
        zombie[i].announce();
    delete[] zombie;
}