#include <iostream>
#include "Job.h"
using namespace std;

Job::Job() {
    name = "";
    description = "";
}

Job::Job(string name, string description) {
    this->name = name;
    this->description = description;
}
Job::~Job() {}

void Job::setName(string name) {
    this->name = name;
}

const string Job::getName() const {
    return name;
}

void Job::print() const {
    cout << "Name: " << name << endl;
    cout << "Description: " << description << endl;
}

Warrior::Warrior(string description) : Job("warrior", description) {
    atk = 10;
    def = 10;
}

Warrior::~Warrior() {}

float Warrior::getAtk() const {
    return atk;
}

float Warrior::getDef() const {
    return def;
}