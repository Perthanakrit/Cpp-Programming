#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
using namespace std;
class Character {
protected:
    string name;
    float health;
    float attack;
    float defense;
    int level;
public:
    Character();
    Character(string, float, float, float);

    void setAttack(float);
    void setDefense(float);
    float getDefense();
    float getHealth();
    int getLevel();

    virtual void attacking(Character*) = 0;
    void getDamage(float);
    virtual void printInfo() = 0;
};

#endif