#include <iostream>

class Hero : public Character
{

private:
    std::string name;
    std::string getName() { return name; }

public:
    int getAttack() { return attack_point; };
    int getHealth() { return health; };
    int getArmor() { return armor; };

    void setName(std::string name) { this->name = name; }
    void setAttack(int attack_point = 2) { this->attack_point = attack_point; } //set default heros's damage point to 2
    void setHealth(int health) { this->health = health; }
    void setArmor(int armor) { this->armor = armor; };

    template <class T>
    void attack(T &EnemyObj)
    {
        int Enemy_health = EnemyObj.getHealth();

        std::cout << "\nYou attack to " << EnemyObj.EnemyType << "with damage point:" << this->attack_point;
        std::cout << "\n Old health of " << EnemyObj.EnemyType << " :" << Enemy_health;

        EnemyObj.setHealth(Enemy_health - this->attack_point); //new health = old enemy's helath - hero's damage point(attack point)

        std::cout << "\nNew health of " << EnemyObj.EnemyType << " :" << EnemyObj.getHealth() << "\n"; //get new health
    }
};
/* deneme */