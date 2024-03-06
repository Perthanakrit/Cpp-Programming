#include <iostream>
#include <string>
using namespace std;

class Hero
{
private:
    string name;
    int level;

public:
    Hero() {}
    Hero(string name, int level) : name(name), level(level){};

    string getName()
    {
        return name;
    };

    int getLevel()
    {
        return level;
    }
};

int main()
{
    string name;
    int level;

    cin >> name >> level;

    Hero warrior(name, level);

    cout << warrior.getName() << " " << warrior.getLevel() << endl;
}