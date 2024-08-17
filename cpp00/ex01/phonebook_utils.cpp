#include "phonebook.hpp"

void PhoneBook::add(void)
{
	this->contact[this->index % 8].get_id(this->index % 8);
	
		this->index++;
}

void PhoneBook::print_infos(Contact infos)
{
	std::cout << std::endl;
	std::cout << "Name: " << infos.get_name() << std::endl;
	std::cout << "Surname: " << infos.get_surname() << std::endl;
	std::cout << "Nick Name: " << infos.get_nickname() << std::endl;
	std::cout << "Tel No: " << infos.get_tel() << std::endl;
	std::cout << "Secret: " << infos.get_secret() << std::endl;
	std::cout << std::endl;
}

#include "unistd.h"
static int selectindex()
{
	int i;
	std::string input;

	while (1)
	{
		std::cout << "Enter index >";
		std::cin >> input;
		if (std::cin.eof())
			return (std::cout << std::endl, -1);
		if (input.length() == 1 && std::isdigit(input[0]))
		{
			i = input[0] - '0';
			if (!(i >= 0 && i <= 7))
				std::cout << "Please enter index 0-7" << std::endl;
			else if (i >= 0 && i <= 7)
				break;
		}
		else
			std::cout << "Please enter index 0-7" << std::endl;
	}
	return (i);
}

void PhoneBook::search(void)
{
	int i;
	if (this->index == 0)
	{
		std::cout << "Phonebook is empty" << std::endl;
		return;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|       Inx|      Name|   Surname|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	this->print_line();
	i = selectindex();
	if (i < 0)
		return;
	Contact usr = this->get_usr(i);
	this->print_infos(usr);
}
