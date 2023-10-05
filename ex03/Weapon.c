#include "Weapon.hpp"

Weapon::Weapon(/* args */)
{

}

Weapon::~Weapon()
{

}

std::string const   & getType() const
{
    return (this->type);
}

void    setType(std::string change_type)
{
    this->type = change_type
}