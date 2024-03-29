#include "Character.h"
#include "Player.h"
#include "Job.h"
using namespace std;

int main(int argc, char const *argv[])
{
    // Job
    Job *warrior = new Warrior("A strong warrior");

    Character *p1 = new Player("Player1", 100, 10, 5, *warrior);
    Character *p2 = new Player("Player2", 100, 10, 5, *warrior);

    p1->attacking(p2); // polymorphism

    p1->printInfo();
    puts("-----------");    
    p2->printInfo();

    return 0;
}
