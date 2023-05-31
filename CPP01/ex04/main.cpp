#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    std::string str("");
    std::string tobereplace(av[1]);
    std::string torepla(av[2]);
    std::string line;
    size_t      found;
    size_t      pos(0);
    std::ifstream inFlux("./infile.txt");
    std::ofstream outFlux("./outfile.txt");

    while (getline(inFlux, str))
    {
        line = "";
        pos = 0;
        found = str.find(tobereplace, pos);
        if (found != std::string::npos and tobereplace.length() != 0)
        {
            while (found != std::string::npos)
            {
                line += str.substr(pos, found - pos);
                line += torepla;
                pos = found + torepla.length();
                if (torepla.length() == 0)
                    pos += tobereplace.length();
                found = str.find(tobereplace, pos);
            }
            line += str.substr(pos);
        }
        else
            line = str;
        outFlux << line << std::endl;
    }
    

    
}