#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include "Character.h"
#include "Job.h"

using namespace std;

class Player : public Character {
private:
    Job job;
    // Item item;
    float exp;
    float maxExp;
    void levelUp();

public:
    Player(string, float, float, float, Job&);
    ~Player();

    void attacking(Character *);
    void defend(Character*);

    // void setJob(Job);
    // void setItem(Item);

    void gainExp(float);
    void printInfo();
};

#endif