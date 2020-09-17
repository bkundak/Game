#include <iostream>
#include <string>
#include "character.h"
#include "hero.h"
#include "enemy.h"
#include "input.h"
#include "shop.h"

bool turn(Hero &hero, Ninja &ninja, Monster &monster)
{
    char flag;

    std::cout << "Who do you want to attack\n";
    std::cout << "Press 1 to attack the ninja\n";
    std::cout << "Press 2 to attack the monster\n";

    switch (PromptInt(1, 2))
    {
    case 1:
        Attack(hero, ninja);
        Attack(ninja, hero);
        break;
    case 2:
        Attack(hero, monster);
        Attack(monster, hero);
        break;
    default:
        std::cout << "\nIncorrect input!!";
        break;
    }

    std::cout << "Are you done? [y/n]\n";
    std::cin >> flag;

    return (flag != 'y');
}

int main()
{
    std::string name;
    int flag;
    std::cout << "Enter the name of your character: ";
    InputStr(&name);

    Hero hero(name, 1, 0, 2);
    Ninja ninja(100, 1, 2);
    Monster monster(100, 1, 1);

    do
    {
        std::cout << "What do you want to do?\n";
        std::cout << "[1] Let's kill some monsters\n";
        std::cout << "[2] Shop\n";
        std::cout << "[3] Exit\n";

        flag = PromptInt(1, 3);

        if (flag == 1)
        {
            while (turn(hero, ninja, monster))
                ;
        }

        else if (flag == 2)
        {
            Shop(&hero);
        }
    } while (flag != 3);

    return (0);
}