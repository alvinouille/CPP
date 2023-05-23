
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
    public:
        Contact(void);
        ~Contact(void);
        void    print(std::string message);
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
};

#endif