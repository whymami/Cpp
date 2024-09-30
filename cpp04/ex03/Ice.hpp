#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
    private:
        /* data */
    public:
        Ice(/* args */);
        Ice(const Ice &copy);
        Ice &operator=(const Ice &src);
        Ice *clone() const;
        void use(ICharacter &target);
        ~Ice();
};
