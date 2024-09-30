#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type)
{
}

std::string const &AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter &target)
{
    (void)target;
}

AMateria::AMateria(/* args */)
{
}

AMateria::AMateria(const AMateria &copy)
{
    *this = copy;
}

AMateria &AMateria::operator=(const AMateria &src)
{
    if (this != &src)
    {
        this->type = src.getType();
    }
    return *this;
}

AMateria::~AMateria()
{
}
