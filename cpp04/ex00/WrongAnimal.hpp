#pragma once

#include "iostream"

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal(/* args */);
    WrongAnimal(const WrongAnimal &copy);
    WrongAnimal &operator=(const WrongAnimal &src);
    std::string getType() const;
    void makeSound() const;
    ~WrongAnimal();
};
