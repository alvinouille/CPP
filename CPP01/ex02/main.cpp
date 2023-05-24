#include <iostream>
#include <string>

int main()
{
    std::string str("HI THIS IS BRAIN");
    std::string *stringPTR(&str);
    std::string &stringREF(str);

    std::cout << "string en memoire = " << &str << std::endl;
    std::cout << "adresse stringPTR = " << stringPTR << std::endl;
    std::cout << "adresse stringREF = " << &stringREF << std::endl;
    std::cout << "valeur contenue dans str = " << str << std::endl;
    std::cout << "valeur pointee par stringPTR = " << *stringPTR << std::endl;
    std::cout << "valeur pointee par stringREF = " << stringREF << std::endl;
}