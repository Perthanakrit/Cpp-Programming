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

// Bird class
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

void printAllAttiude(Animal animal)
{
    cout << "Happiness: " << animal.getHappiness() << endl;
    cout << "Energy: " << animal.getEnergy() << endl;
    cout << "Fullness: " << animal.getFullness() << endl;
    cout << "----------------" << endl;
}

int main(int argc, char const *argv[])
{
    Animal animal(-19, 0, 1500);
    Bird *bird = new Bird(10, 20, 30);
    printAllAttiude(animal);

    animal.eat(150);
    printAllAttiude(animal);

    animal.play(2);
    printAllAttiude(animal);

    animal.sleep(3);
    printAllAttiude(animal);

    printf("%s\n", "-----Bird-----");

    bird->fly(2);

    return 0;
}
