
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
    public:
        Contact();
        ~Contact();
        void        print(int i, int flag);
        void        att(void);

    private:
        static void reformat_print(std::string &str);
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
};

#endif