#ifndef JOB_H
#define JOB_H
#include <iostream>
using namespace std;

class Job {
protected:
    string name;
    string description;
public:
    Job();
    Job(string name, string description);
    ~Job();
    void setName(string name);
    const string getName() const;
    void print() const;
};

class Warrior : public Job {
private:
    float atk;
    float def;
public:
    Warrior(  string description);
    ~Warrior();

    float getAtk() const;
    float getDef() const;
};

#endif