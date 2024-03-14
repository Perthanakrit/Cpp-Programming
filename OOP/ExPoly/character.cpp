#include <iostream>
#include <cmath>

using namespace std;

class GameCharacter
{
public:
    GameCharacter()
    {
        cout << "GameCharacter created" << endl;
    }

    virtual void fight()
    {
        cout << "Fight!" << endl;
    }
};

class Enemy : public GameCharacter
{
public:
    Enemy() : GameCharacter()
    {
    }

    virtual void fight()
    {
        cout << "Enemy ";
        GameCharacter::fight();
    }
};

class Boss : public Enemy
{
public:
    virtual void fight()
    {
        cout << "Bossy " << endl;
        Enemy::fight();
    }
};

class Minion : public Enemy
{
public:
    virtual void fight()
    {
        cout << "Minion ";
        Enemy::fight();
    }
};

int main(int argc, char const *argv[])
{
    GameCharacter *gamechar = new GameCharacter();
    GameCharacter *enemy = new Enemy();
    GameCharacter *boss = new Boss();

    GameCharacter *characters[3] = {gamechar, enemy, boss};
    for (int i = 0; i < 3; i++)
        characters[i]->fight();

    Enemy *gege = new Minion();
    gege->fight();

    return 0;
}
