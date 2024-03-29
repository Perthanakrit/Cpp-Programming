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

    virtual void fight() = 0;

    virtual void getEnemy(GameCharacter &enemy) = 0;
};

class Enemy : public GameCharacter
{
public:
    Enemy() : GameCharacter()
    {
    }

    void fight()
    {
        cout << "Enemy" << endl;
    }

    void getEnemy(Enemy &enemy)
    {
        cout << "Minion ";
        enemy.fight();
    }
};

class Boss : public Enemy
{
public:
    void getEnemy(Enemy &enemy)
    {
        cout << "Minion ";
        enemy.fight();
    }
};

class Minion : public Enemy
{
public:

    void getEnemy(Enemy &enemy)
    {
        cout << "Minion ";
        enemy.fight();
    }
};

class Player : public GameCharacter
{
public:
    void fight()
    {
        cout << "Player ";
        Enemy::fight();
    }
    void getEnemy(Enemy &enemy)
    {
        cout << "Player ";
        enemy.fight();
    }
};


int main(int argc, char const *argv[])
{
    GameCharacter *gamechar = new GameCharacter();
    Enemy *enemy = new Enemy();
    Boss *boss = new Boss();

    GameCharacter *characters[3] = {gamechar, enemy, boss};
    for (int i = 0; i < 3; i++)
        characters[i]->fight();

    Enemy *gege = new Minion();
    gege->fight();

    Player *player = new Player();
    player->getEnemy(*gege);

    return 0;
}
