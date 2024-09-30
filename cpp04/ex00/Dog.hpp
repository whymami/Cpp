#pragma once

#include "iostream"
#include "Animal.hpp"

class Dog : public Animal
{
private:
    /* data */
public:
    Dog(/* args */);
    Dog(const Dog &copy);
    Dog &operator=(const Dog &src);
    void makeSound() const;
    ~Dog();
};
