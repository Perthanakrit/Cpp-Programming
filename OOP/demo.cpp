#include <iostream>
using namespace std;

class Rectangle
{
public:
    double width;
    double length;

    Rectangle(double w = 1, double l = 1) : width(w), length(l)
    {
        if (w < 0)
            width = 1;
        if (l < 0)
            length = 1;
    }
};

int main(int argc, char const *argv[])
{
    Rectangle r1(10, 5);
    // Rectangle r2;
    // Rectangle r3();

    return 0;
}
