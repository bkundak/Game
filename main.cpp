//To Do
/*
        -what happens if health=0
        -Characters's special functions ?
        -Set Armors (now characters have infinite Armor)
        -create Game loop
    */
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

    std::cout << "Who do you want to attack" << std::endl;
    std::cout << "press 1 to attack the ninja " << std::endl;
    std::cout << "For attack to monster press 2" << std::endl;

    std::cin >> s;
    if (s = 1)
    {
        Attack(hero, ninja); //hero atacks to ninja
        Attack(ninja, hero); //ninja atacks to hero
    }
    else if (s = 2)
    {
        Attack(hero, monster); //again hero attack to monster
        Attack(monster, hero); //monster atacks to hero
    }

    std::cout << "Are you done? [y/n]" << std::endl;
    std::cin >> flag;

    return (flag != 'y');
}

int main()
{
    std::cout << "Enter the name of your character: ";
    std::string name;
    std::cin >> name;
    std::cout << std::endl;
    Hero hero(name, 1, 1, 2);
    Ninja ninja(100, 1, 2);
    Monster monster(100, 1, 1);
    int flag = 0;
    do
    {
        std::cout << "What do you want to do?" << std::endl;
        std::cout << "[1] Let's kill some monsters" << std::endl;
        std::cout << "[2] Shop" << std::endl;
        std::cout << "[3] Exit" << std::endl;

        std::cin >> flag;

        if (flag = 1)
        {
            while (turn(hero, ninja, monster))
                ;
        }

        if (flag = 2)
        {
            hero.Shop(hero);
        }
        if (flag = 3 )
         break;
    } while (flag != 3);

    return (0);
}