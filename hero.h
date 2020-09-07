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

    int PromptInt(int min, int max)
    {
        int s;
        do
        {
            std::cout << "\nPlease enter a valid number: ";
            std::cin >> s;
        } while ( s < min || s > max);
        return s;
    }

    void Shop(Hero &player)
    {
      
        std::cout << "What do you want to do?\n";
        std::cout << "[1] Restore health\n";
        std::cout << "[2] Upgrade attack point\n";
        std::cout << "[3] Upgrade armor\n";

        switch (PromptInt(1,3))
        {
        case 1:
            player.health = 100;
            break;
        case 2:
            player.attack_point++;
            break;
        case 3:
            player.armor++;
            break;
        default:
            std::cout << "\nIncorrect input!!";
            break;
        }
    }
};