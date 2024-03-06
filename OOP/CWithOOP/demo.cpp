#include <iostream>
using namespace std;

class Pet
{
private:
    string name;
    int age;
    string type;

public:
    Pet() : name(""), age(0), type("") {}
    Pet(string name, int age, string type) : name(name), age(age), type(type) {}

    string getName()
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }
};

class Person
{
private:
    string name;
    int age;
    Pet pet;

public:
    Person() : name(""), age(0), pet() {}
    Person(string name, int age, Pet pet) : name(name), age(age), pet(pet) {}

    string getName()
    {
        return name;
    }

    Pet getPet()
    {
        return pet;
    }

    int getAge()
    {
        return age;
    }
};

int main(int argc, char const *argv[])
{
    Pet tom("Tom", 3, "Cat");
    Person person("John", 20, tom);

    cout << person.getPet().getName() << endl;

    return 0;
}
