#include "Contact.hpp"

Contact::Contact()
{
    // std::cout << "Object contact created" << std::endl;
}

Contact::~Contact()
{
    // std::cout << "Object contact destroyed" << std::endl;
}

void    Contact::reformat_print(std::string &str)
{
    size_t length(0);
    size_t j(0);
    std::string reformated;

    length = str.length();
    if (length > 10)
    {
        reformated = str.substr(0, 10);
        reformated[9] = '.';
        length = 10;
    }
    else
        reformated = str;
    for (j = 0 ; j < (10 - length) ; j++)
        std::cout << " ";
    
    std::cout << reformated << "|";
}

void    Contact::print(int i, int flag)
{
    switch (flag)
    {
        case 0:
            std::cout << "         " << i << "|";
            reformat_print(firstName);
            reformat_print(lastName);
            reformat_print(nickName);
            std::cout << std::endl;
            break;
        case 1:
            std::cout << "firstName : " << firstName << std::endl;
            std::cout << "lastName : " << lastName << std::endl;
            std::cout << "nickName : " << nickName << std::endl;
            std::cout << "phoneNumber : " << phoneNumber << std::endl;
            std::cout << "darkestSecret : " << darkestSecret << std::endl;
            break;
    }
    return ;
}

void    Contact::att(void)
{
    do
    {
        std::cout << "First name : ";
        getline(std::cin, firstName);
    } while (firstName == "");
    do
    {
        std::cout << "Last name : ";
        getline(std::cin, lastName);
    } while (lastName == "");
    do
    {
        std::cout << "Nickname : ";
        getline(std::cin, nickName);
    } while (nickName == "");
    do
    {
        std::cout << "Phone number : ";
        getline(std::cin, phoneNumber);
    } while (phoneNumber == "");
    do
    {
        std::cout << "Darkest secret : ";
        getline(std::cin, darkestSecret);
    } while (darkestSecret == "");
}