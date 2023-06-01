#include <iostream>
#include <fstream>
#include <string>

# define EXIT_FAILURE 1

int main(int ac, char **av)
{
    std::string str("");
    std::string oldstr(av[2]);
    std::string newstr(av[3]);
    std::string line;
    size_t      found;
    size_t      pos(0);

    if (ac != 4)
    {
        std::cout << "ERROR : Wrong number of arguments" << std::endl;
        return (EXIT_FAILURE);
    }
    std::ifstream inFlux(av[1]);
    std::ofstream outFlux((std::string(av[1]) + ".replace").c_str());
    if (!inFlux or !outFlux)
    {
        std::cout << "ERROR : File not found" << std::endl;
        return (EXIT_FAILURE);
    }
    while (getline(inFlux, str))
    {
        line = "";
        pos = 0;
        found = str.find(oldstr, pos);
        if (found != std::string::npos and oldstr.length() != 0)
        {
            while (found != std::string::npos)
            {
                line += str.substr(pos, found - pos);
                line += newstr;
                pos = found + oldstr.length();
                found = str.find(oldstr, pos);
            }
            line += str.substr(pos);
        }
        else
            line = str;
        outFlux << line << std::endl;
    }
    

    
}