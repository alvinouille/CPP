#include "Zombie.h"

int main()
{
    Zombie *zombie;

    zombie = newZombie("Gilles_The_First");
    zombie->announce();
    randomChump("Bob_The_Second");
    delete zombie;
}