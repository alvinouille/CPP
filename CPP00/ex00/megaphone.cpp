#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char **av)
{
    std::string str("");
    int i;

    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for(i = 1 ; i < ac ; i++)
    {
        str += av[i];
    }
    for(i = 0; i < (int)str.length() ; i++)
    {
        if (std::isalpha(str[i]))
            str[i] = std::toupper(str[i]);
    }
    std::cout << str << std::endl;
}