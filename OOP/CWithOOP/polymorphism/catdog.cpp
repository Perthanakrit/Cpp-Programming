#include <iostream>
using namespace std;

class Animal
{
private:
    string name;

public:
    Animal()
    {
    }

    string getName()
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    virtual void makeSound() = 0;
};

class Dog : public Animal
{
public:
    Dog() : Animal() {}

    void makeSound()
    {
        cout << "Hong Hong!" << endl;
    }
};

class Cat : public Animal
{
public:
    Cat() : Animal() {}

    void makeSound()
    {
        cout << "Meow Meow!" << endl;
    }
};

int main(int argc, char const *argv[])
{
    Animal *farm = new Animal()[2];

    farm[0] = new Dog();
    farm[1] = new Cat();

    return 0;
}
