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

int main()
{
    Hero hero;
    Ninja ninja;
    Monster monster;

    hero.setHealth(100); //set all characters health %100
    ninja.setHealth(100);
    monster.setHealth(100);

    //Set all character's damagepoint
    ninja.setAttack();   //set ninnja's atack point default=2
    monster.setAttack(); //set monster's atack point default =1  you can cahange if you send a value
    hero.setAttack();    //default 2

    //-------------------------------------------------------------------
    ninja.attack(hero);   //ninja atacks to hero
    hero.attack(ninja);   //hero atacks to ninja
    monster.attack(hero); //monster atacks to hero
    hero.attack(monster); //again hero attack to monster
    ninja.attack(hero);
    hero.attack(monster); //hero atacks to monster
    return (0);
}
/*deneme*/