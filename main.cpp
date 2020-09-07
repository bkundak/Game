#include <iostream>
#include <string>
#include "character.h"
#include "hero.h"
#include "enemy.h"
#include "select.h"

bool turn(Hero &hero, Ninja &ninja, Monster &monster)
{
    int s;
    char flag;

    std::cout << "Who do you want to attack\n";
    std::cout << "Press 1 to attack the ninja\n";
    std::cout << "Press 2 to attack the monster\n";

    std::cin >> s;
    if (s == 1)
    {
        Attack(hero, ninja); //hero atacks to ninja
        Attack(ninja, hero); //ninja atacks to hero
    }
    else if (s == 2)
    {
        Attack(hero, monster); //again hero attack to monster
        Attack(monster, hero); //monster atacks to hero
    }

    std::cout << "Are you done? [y/n]\n";
    std::cin >> flag;

    return (flag != 'y');
}

int main()
{
    std::cout << "Enter the name of your character: ";
    std::string name;
    std::cin >> name;

    Hero hero(name, 1, 0, 2);
    Ninja ninja(100, 1, 2);
    Monster monster(100, 1, 1);
    
    int flag = 0;
    
    do
    {
        std::cout << "What do you want to do?\n";
        std::cout << "[1] Let's kill some monsters\n";
        std::cout << "[2] Shop\n"; 
        std::cout << "[3] Exit\n";

        std::cin >> flag;

        if (flag == 1)
        {
            while (turn(hero, ninja, monster))
                ;
        }

        if (flag == 2)
        {
            hero.Shop(hero);
        }
    } while (flag != 3);

    return (0);
}