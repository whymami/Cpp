#include "phonebook.hpp"

void Contact::get_id(void)
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

}