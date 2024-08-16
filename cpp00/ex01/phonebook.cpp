#include "phonebook.hpp"

Contact PhoneBook::get_usr(int i)
{
    return(this->contact[i]);
}

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

void max_len(std::string str)
{
    str.resize(10);
    str[9] = '.';
    std::cout << str << "|";
}

void print_info(std::string info)
{
    int space_count;
    std::string new_str;

    if (info.length() > 10)
        return (max_len(info));
    space_count = 10 - info.length();
    while (space_count > 0)
    {
        new_str.append(" ");
        space_count--;
    }
    new_str.append(info);
    std::cout << new_str << "|" ;
}

void PhoneBook::print_line(void)
{
    int i;
    int control;

    i = -1;
    if (this->index > 7)
        control = 8;
    else
        control = this->index;
    while (++i < control)
    {
        std::cout << "|         " << i << "|";
        print_info(this->contact[i].get_name());
        print_info(this->contact[i].get_surname());
        print_info(this->contact[i].get_nickname());
        std::cout << std::endl;
        std::cout << "|----------|----------|----------|----------|" << std::endl;
    }
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
            book.search();
        else if (command == "3" || command == "EXIT" || command == "exit")
            break;
    }
}
