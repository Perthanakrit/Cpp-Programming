#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

typedef struct _point
{
    double xPosition;
    double yPosition;
} point;

class Circle
{
public:
    point center;
    double radius;

    Circle(point c, double r) : radius(r)
    {
        center = c;
    }

    double area()
    {
        return M_PI * radius * radius;
    }

    double distanceFromCenter(point pt)
    {
        double dX = pt.xPosition - center.xPosition;
        double dY = pt.yPosition - center.yPosition;
        return (sqrt(dX * dX + dY * dY));
    }

    int contains(point pt)
    {
        return (this->distanceFromCenter(pt) <= radius) ? 1 : 0;
    }
};

int main(int argc, char const *argv[])
{
    point ct = {0.0, 0.0};
    double r;
    point ptC = {0.0, 0.0};

    cout << "Center of Circle: ";
    cin >> ct.xPosition >> ct.yPosition;
    cout << "Radius of Circle: ";
    cin >> r;
    cout << "Point to Check: ";
    cin >> ptC.xPosition >> ptC.yPosition;

    Circle c1(ct, r);

    cout << "Area of Circle is " << c1.area() << endl;
    cout << "Distance from Center to Point "
         << "(" << ptC.xPosition
         << ", " << ptC.yPosition << ")"
         << " is " << c1.distanceFromCenter(ptC) << endl;
    if (c1.contains(ptC))
    {
        cout << "This circle contains this point." << endl;
    }
    else
    {
        cout << "This point is not in this circle." << endl;
    }
}
