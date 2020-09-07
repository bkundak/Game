#include <iostream>
#include "character.h"

class Hero : public Character
{

private:
    std::string name;

public:
    Hero(std::string _name, int _health, int _armor, int _attack) : name(_name), Character(_health, _armor, _attack) {}
    std::string getName() { return name; }
    std::string getType() override { return "Hero"; }

    void Shop(Hero player)
    {

        int flag=0;

        std::cout << "What fo you want to buy?" << std::endl;
        std::cout << "For restore healt press 1 " << std::endl;
        std::cout << "For upgrade attack point perss 2 " << std::endl;
        std::cout << "For upgrade attack point perss 3" << std::endl;

        std::cin >> flag;

        if (flag = 1)
        {
            player.health = 100;
        }
        if (flag = 2)
        {
            player.attack_point++;
        }
        if (flag = 3)
        {
            player.armor++;
        }
    }
};