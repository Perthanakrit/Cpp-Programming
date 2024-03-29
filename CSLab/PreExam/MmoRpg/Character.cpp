#include <iostream>
#include "Character.h"
using namespace std;

Character::Character() {
    name = "Default";
    health = 0;
    attack = 0;
    defense = 0;
    level = 0;
}

Character::Character(string name, float health, float attack, float defense) {
    this->name = name;
    this->health = health;
    this->attack = attack;
    this->defense = defense;
    this->level = 1;
}

void Character::setAttack(float atk) {
    if (atk > 0)
        this->attack += atk;
}

void Character::setDefense(float def) {
    if (def > 0)
        this->defense += def;
}

float Character::getDefense() {
    return defense;
}

float Character::getHealth() {
    return health;
}

void Character::getDamage(float damage) {
    health -= damage;
}

void Character::attacking(Character* target) {
    float damage = attack - target->getDefense();
    if (damage < 0)
        damage = 0;
    target->getDamage(damage);
}

void Character::printInfo() {
    cout << "Name: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defense << endl;
    cout << "Level: " << level << endl;
}