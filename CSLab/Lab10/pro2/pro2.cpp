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
private:
    point center;
    double radius;

public:
    Circle(double x, double y, double r) : radius(r)
    {
        center.xPosition = x;
        center.yPosition = y;
    }

    double area()
    {
        return M_PI * radius * radius;
    }
};

int main()
{
    // สร้าง Object เพื่อทดสอบด้วยตัวเอง
}