#include <iostream>
using namespace std;

struct Passage
{
    int takeOn;
    int takeOff;
    int waitTime;
};

int main(int argc, char const *argv[])
{
    int seats, timing, stations, passengers;

    int runningTime = 0;
    Passage *passageOnTrian = new Passage[seats];

    cin >> seats >> timing >> stations >> passengers;

    for (int i = 0; i < passengers; i++)
    {
        }

    return 0;
}
