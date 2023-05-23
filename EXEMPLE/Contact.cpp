#include "Contact.hpp"

Contact::Contact(void)
{
    std::cout << "Constructeur contact called" << std::endl;
    return ;
}

Contact::~Contact(void)
{
    std::cout << "Destructeur contact called" << std::endl;
    return ;
}

void    Contact::print(std::string message)
{
    std::cout << message << std::endl;
    return ;
}