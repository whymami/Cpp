#pragma once

#include "iostream"
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
    /* data */
public:
    WrongCat(/* args */);
    WrongCat(const WrongCat &copy);
    WrongCat &operator=(const WrongCat &src);
    void makeSound() const;
    ~WrongCat();
};
