#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Job.h"
using namespace std;

void Player::levelUp()
{
    level++;
    maxExp += 20;
    exp = 0;
    attack += 10;
    defense += 5;
    health += 50;
}

Player::Player(string n, float health, float atk, float def, Job &job) : Character(n, health, atk, def) 
{
    exp = 0;
    maxExp = 100;
    this->job = job;
}

Player::~Player()
{
    cout << "Player " << name << " has been destroyed" << endl;
}

void Player::attacking(Character *target)
{
    Character::attacking(target);
}

void Player::gainExp(float exp)
{
    this->exp += exp;
    if (this->exp >= maxExp)
        levelUp();
}

void Player::printInfo()
{
    Character::printInfo();
    cout << "Job: " << job.getName() << endl;
}

