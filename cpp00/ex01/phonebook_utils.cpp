#include "phonebook.hpp"

void PhoneBook::add(void)
{
	if (this->index == 8)
		this->index = 0;
	this->contact[this->index++].get_id();
}