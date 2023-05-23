#include "Contact.hpp"
#include "Repertoire.hpp"

int main()
{
    std::string str;
    Contact nouveau;
    Repertoire repertoire;
    int i(-1);
    
    while (str != "EXIT")
    {
        getline(std::cin, str);
        if (str == "ADD")
        {
            i++;
            repertoire.add_contact(i);
            std::cout << "<<<< Contact well added >>>>" << std::endl;
        }
        if (str == "SEARCH")
        {
            if (i == -1)
                continue;
            std::cout << "<<<< Contacts list >>>>" << std::endl;
            repertoire.print(i);
            while (str[0] - 48 > i or str[0] - 48 < 0 or str.length() != 1)
                getline(std::cin, str);
            repertoire.get(str[0] - 48).print(0, 1);
        }
    }
    return (0);
}