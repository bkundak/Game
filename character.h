#include<iostream>
class Character{

    protected:
      int health;
      int armor;
      int attack_point;

      virtual void attack(){};

      virtual int getAttack()=0;

      virtual int getHealth()=0;
    	virtual int getArmor()=0;


      virtual void setArmot(){};
      virtual void setHealth(){};
      virtual void setAttack(){};
};
