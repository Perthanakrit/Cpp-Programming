#include <iostream>
using namespace std;

int readInt()
{
    int value;
    cin >> value;
    return value;
}

int main()
{
    cout << "Hello Makefile" << endl;
    int number = readInt();
    cout << "Number: " << number << endl;

    return 0;
}