#pragma once
#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria(/* args */);
        AMateria(const AMateria &copy);
        AMateria &operator=(const AMateria &src);
        virtual ~AMateria();
        AMateria(std::string const &type);
        std::string const &getType() const;
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};
