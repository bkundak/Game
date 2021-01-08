#include <iostream>
#include "character.h"
#include "input.h"

class Hero : public Character
{

private:
    std::string name;

public:
    Hero(std::string _name, int _health, int _armor, int _attack) : name(_name), Character(_health, _armor, _attack) {}
    std::string getName() { return name; }
    std::string getType() override { return "Hero"; }
};