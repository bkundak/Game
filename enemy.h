#include <iostream>
#include "character.h"

void Attack(Character &player, Character &enemy)
{
    int hero_health = player.getHealth();

    printf("%s attacks you with %d\n", enemy.getType().c_str(), enemy.getAttack());
    //std::cout << "\nNinja attack atack to you with " << attack_point << " attack point" << std::endl;
    std::cout << "Your old health:" << player.getHealth();

    player.takeDamage(enemy.getAttack());

    std::cout << "\nYour new Health:" << player.getHealth() << std::endl;
}

class Ninja : public Character
{

private:
    void shadowAttack();

public:
    std::string getType() override { return "Ninja"; }

    using Character::Character;
};

class Monster : public Character
{

private:
    void bite();

public:
    using Character::Character;
    std::string getType() override { return "Monster"; }
};
