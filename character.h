#pragma once

#include <iostream>
#include <string>

class Character
{
public:
  Character(int _health, int _armor, int _attack) : health(_health), armor(_armor), attack_point(_attack) {}

  int getAttack() const { return attack_point; };
  int getHealth() const { return health; };
  int getArmor() const { return armor; };
  virtual std::string getType() = 0;

  bool takeDamage(int amount)
  {
    if (health - amount >= 0)
    {
      health -= amount;
      return true;
    }

    return false;
  }
  // virtual void setArmor(int value) = 0;
  // virtual void setHealth(int value) = 0;
  // virtual void setAttack(int value)= 0;

protected:
  int health;
  int armor;
  int attack_point;
};