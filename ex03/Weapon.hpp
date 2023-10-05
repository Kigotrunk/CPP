#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class Weapon
{
private:
    std::string Type;
public:
    Weapon(/* args */);
    ~Weapon();
    std::string const   & getType() const;
    void	setType(std::string change_type);
};

#endif