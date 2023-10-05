#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void    attack() const{
    std::cout << this->name << "attacks with their" << this->weapon.getType() << std::endl;
}