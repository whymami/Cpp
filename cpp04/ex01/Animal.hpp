#pragma once

#include "iostream"

class Animal
{
protected:
    std::string type;

public:
    Animal(/* args */);
    Animal(const Animal &copy);
    Animal &operator=(const Animal &src);
    std::string getType() const;
    virtual void makeSound() const;
    virtual ~Animal();
};
