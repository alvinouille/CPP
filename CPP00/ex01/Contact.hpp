
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
    public:
                    Contact();
                    ~Contact();
        static void reformat_print(std::string &str);
        void        print(int i, int flag);
        void        att(void);
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
};

#endif