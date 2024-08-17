#include "phonebook.hpp"

void Contact::get_id(int i)
{
    std::cout << "Name: ";
        getline(std::cin, this->name);
        if (this->name.empty())
        {
            std::cout << "Name cannot be left blank" << std::endl;
            std::cin.clear();
            return ;
        }
    std::cout << "Surname: ";
        getline(std::cin, this->surname);
        if (this->surname.empty())
        {
            std::cout << "Surname cannot be left blank" << std::endl;
            std::cin.clear();
            return;
        }
    std::cout << "Nickname: ";
        getline(std::cin, this->nickname);
        if (this->nickname.empty())
        {
            std::cout << "Nickname cannot be left blank" << std::endl;
            std::cin.clear();
            return;
        }
    std::cout << "Tel: ";
        getline(std::cin, this->tel);
        if (this->tel.empty())
        {
            std::cout << "Tel cannot be left blank" << std::endl;
            std::cin.clear();
            return;
        }
    std::cout << "Secret: ";
        getline(std::cin, this->secret);
        if (this->secret.empty())
        {
            std::cout << "Secret cannot be left blank" << std::endl;
            std::cin.clear();
            return;
        }
    this->index = i;
}

std::string Contact::get_name(void)
{
    return (this->name);
}

std::string Contact::get_surname(void)
{
    return (this->surname);
}

std::string Contact::get_nickname(void)
{
    return (this->nickname);
}

std::string Contact::get_secret(void)
{
    return (this->secret);
}

std::string Contact::get_tel(void)
{
    return (this->tel);
}

int Contact::get_inx(void)
{
    return (this->index);
}
