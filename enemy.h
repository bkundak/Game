#include <iostream>

class Ninja : public Character
{

private:
    void shadowAttack();

public:
    const std::string EnemyType = "|Ninja|";
    int getAttack() { return attack_point; };
    int getHealth() { return health; };
    int getArmor() { return armor; };

    void setAttack(int attack_point = 2) { this->attack_point = attack_point; }; //set the default damage point 2
    void setHealth(int health) { this->health = health; };
    void setArmor(int armor) { this->armor = armor; };

    void attack(Hero &obj)
    {
        int hero_health = obj.getHealth();

        std::cout << "\nNinja attack atack to you with " << attack_point << " attack point" << std::endl;
        std::cout << "Your old health:" << obj.getHealth();

        obj.setHealth(hero_health - this->attack_point);

        std::cout << "\nYour new Health:" << obj.getHealth() << std::endl;
    };
};

class Monster : public Character
{

private:
    void bite();

public:
    const std::string EnemyType = "|Monster|";
    int getAttack() { return attack_point; };
    int getHealth() { return health; };
    int getArmor() { return armor; };

    void setAttack(int attack_point = 1) { this->attack_point = attack_point; }; //set default damage point 1;
    void setHealth(int health) { this->health = health; };
    void setArmor(int armor) { this->armor = armor; };

    void attack(Hero &obj)
    {
        int hero_health = obj.getHealth();

        std::cout << "\nMonster attack atack to you with " << attack_point << " attack point" << std::endl;
        std::cout << "Your old health:" << obj.getHealth();

        obj.setHealth(hero_health - this->attack_point);

        std::cout << "\nYour new Health:" << obj.getHealth() << std::endl;
    };
};
