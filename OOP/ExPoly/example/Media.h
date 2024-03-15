#include <iostream>
using namespace std;

class Media
{
private:
    string title;
    int sizeInBytes;

public:
    Media(string title);
    string getTitle();
    int getSizeInBytes();
    double getSeizeInKB();
};