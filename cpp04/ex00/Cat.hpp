#pragma once

#include "iostream"
#include "Animal.hpp"

class Cat : public Animal
{
private:
    /* data */
public:
    Cat(/* args */);
    Cat(const Cat &copy);
    Cat &operator=(const Cat &src);
    void makeSound() const;
    ~Cat();
};
