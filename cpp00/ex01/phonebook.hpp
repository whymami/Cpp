# include <iostream>
#include "string"

class Contact
{
    private:
        int index;
        std::string name;
        std::string surname;
        std::string nickname;
        std::string tel;
        std::string secret;
    public:
        void get_id(int i);
        std::string get_name(void);
        std::string get_surname(void);
        std::string get_nickname(void);
        std::string get_tel(void);
        std::string get_secret(void);
        int get_inx(void);
};

class PhoneBook
{
    private:
        int index;
        Contact contact[8];
    public:
        PhoneBook(void);
        void add(void);
        void search(void);
        void print_line(void);
        Contact get_usr(int i);
        void print_infos(Contact);
};
