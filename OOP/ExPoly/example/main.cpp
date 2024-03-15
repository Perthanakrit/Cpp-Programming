#include <iostream>
#include "Media.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Media *media = new Media("Hello");

    cout << media->getTitle() << endl;
    return 0;
}
