# include <iostream>
#include "string"

class Contact
{
    private:
        std::string name;
        std::string surname;
        std::string nickname;
        std::string tel;
        std::string secret;
    public:
        void get_id(void);
};

class PhoneBook
{
    private:
        int index;
        Contact contact[8];
    public:
        PhoneBook(void);
        // ~PhoneBook(void);
        void add(void);
        void searhc(void);
};
