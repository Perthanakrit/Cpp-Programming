#include <iostream>
using namespace std;

class Animal
{

private:
    string name;
    int age;

public:
    Animal(string n, int a) : name(n), age(a) {}

    string getName() { return name; }
    int getAge() { return age; }

    void eat(string food)
    {
        cout << name << " is eating " << food << endl;
    }

    void sleep()
    {
        cout << name << " is sleeping..." << endl;
    }

    void makeSound()
    {
        cout << name << " is making a sound" << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(string n, int a) : Animal(n, a) {}

    // redefine
    void makeSound()
    {
        cout << getName() << " is woofing" << endl;
    }
};

class Cat : public Animal
{
public:
    Cat(string n, int a) : Animal(n, a) {}

    // redefine
    void makeSound()
    {
        cout << getName() << " is meowing" << endl;
    }
};

int main()
{
    Dog dobby("Dobby", 2);
    Cat bobby("Bobby", 4);
    Animal *a1 = &dobby;

    // dobby.eat("meat");
    dobby.makeSound();
    // dobby.sleep();

    // bobby.eat("fish");
    bobby.makeSound();
    // bobby.sleep();

    a1->makeSound();

    return 0;
}