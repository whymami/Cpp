#include "phonebook.hpp"

std::string get_input(void)
{
    std::string command;

    std::cout << "1: ADD" << std::endl;
    std::cout << "2: SEARCH" << std::endl;
    std::cout << "3: EXIT" << std::endl;
    std::cout << "input> ";
    std::cin >> command;
    if (std::cin.eof())
        command = "EXIT";
    return (command);
}

PhoneBook::PhoneBook(void)
{
    this->index = 0;
}

int main(void)
{
    PhoneBook book;
    while (true)
    {
        std::string command = get_input();
        if (command == "1" || command == "ADD" || command == "add")
        {
            std::cin.ignore();
            book.add();
        }
        else if (command == "2" || command == "SEARCH" || command == "search")
            book.add();
        else if (command == "3" || command == "EXIT" || command == "exit")
            break;
    }
}
