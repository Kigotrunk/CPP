#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"

class HumanB
{
private:
    std::string _name;
    Weapon &_Weapon;
public:
    HumanB(std::string name);
    ~HumanB();
    void    attack() const;
};

#endif