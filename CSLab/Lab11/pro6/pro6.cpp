#include <iostream>
using namespace std;

class Animal
{
protected:
    int happiness;
    int energy;
    int fullness;
    const int MAX_HAPPINESS = 100;
    const int MAX_ENERGY = 100;
    const int MAX_FULLNESS = 100;
    void limitStat();

public:
    Animal(int, int, int);
    int getHappiness();
    int getEnergy();
    int getFullness();
    void eat(int);
    void play(int);
    void sleep(int);
};

Animal::Animal(int happiness, int energy, int fullness)
{
    this->happiness = happiness;
    this->energy = energy;
    this->fullness = fullness;

    limitStat();
}

int Animal::getHappiness() { return happiness; }
int Animal::getEnergy() { return energy; }
int Animal::getFullness() { return fullness; }

void Animal::limitStat()
{
    if (happiness > MAX_HAPPINESS)
    {
        happiness = MAX_HAPPINESS;
    }
    if (happiness < 0)
    {
        happiness = 0;
    }

    if (energy > MAX_ENERGY)
    {
        energy = MAX_ENERGY;
    }
    if (energy < 0)
    {
        energy = 0;
    }

    if (fullness > MAX_FULLNESS)
    {
        fullness = MAX_FULLNESS;
    }
    if (fullness < 0)
    {
        fullness = 0;
    }
}

void Animal::eat(int food)
{
    if (food < 0)
    {
        return;
    }

    fullness += food;

    if (fullness > MAX_FULLNESS)
    {
        happiness -= 10;
    }
    limitStat();
}

void Animal::play(int hour)
{
    if (energy <= 0 || fullness <= 0)
    {
        return;
    }

    if (hour < 0)
    {
        return;
    }

    // Energy decreases by 10 per hour
    energy -= (10 * hour);

    // Fullness decreases by 20 per hour
    fullness -= (20 * hour);

    // Happiness increases by 5 per hour
    happiness += (5 * hour);

    limitStat();
}

void Animal::sleep(int hour)
{
    if (hour < 0)
    {
        return;
    }

    // Energy increases by 10 per hour and fullness decreases by 10 per hour
    energy += (10 * hour);
    fullness -= (10 * hour);
    limitStat();
}

// Brid
class Bird : public Animal
{
public:
    Bird(int, int, int);
    void fly(int);
    void sing();
};

Bird::Bird(int happiness, int energy, int fullness) : Animal(happiness, energy, fullness) {}

void Bird::fly(int hour)
{
    if (hour < 0)
    {
        return;
    }
    energy -= (5 * hour);
    Animal::limitStat();
}

void Bird::sing()
{
    happiness += 5;
    Animal::limitStat();
}

// Pet class
class Pet
{
protected:
    string name;

public:
    Pet(string);
    string getName();
    void setName(string);
};

Pet::Pet(string name)
{
    this->name = name;
}

string Pet::getName() { return name; }
void Pet::setName(string name) { this->name = name; }

// OwnedBird
class OwnedBird : public Bird, public Pet
{
public:
    OwnedBird(string, int, int, int);
};

OwnedBird::OwnedBird(string name, int happiness, int energy, int fullness) : Pet(name), Bird(happiness, energy, fullness)
{
}

void printAllAttiude(Bird animal)
{
    cout << "Happiness: " << animal.getHappiness() << endl;
    cout << "Energy: " << animal.getEnergy() << endl;
    cout << "Fullness: " << animal.getFullness() << endl;
    cout << "----------------" << endl;
}

int main()
{
    char action;
    int hour;
    int happiness, energy, fullness;
    cin >> happiness >> energy >> fullness;
    OwnedBird animal("Dobby", happiness, energy, fullness);
    while (1)
    {
        cin >> action;
        if (action == 'q')
            break;
        cin >> hour;
        switch (action)
        {
        case 'e':
            animal.eat(hour);
            break;
        case 'p':
            animal.play(hour);
            break;
        case 's':
            animal.sleep(hour);
            break;
        case 'f':
            animal.fly(hour);
            break;
        case 'i':
            for (int i = 0; i < hour; i++)
                animal.sing();
            break;
        case 'n':
            if (hour < 5)
                animal.setName("Debby");
            else
                animal.setName("Shogun");
            break;
        }
    }

    cout << animal.getName() << endl;
}
