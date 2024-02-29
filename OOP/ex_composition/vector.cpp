#include <iostream>
using namespace std;

class Point
{
private:
    double x, y, z;

public:
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y), z(z) {}

    Point Add(Point other)
    {
        Point p;
        p.x = this->x + other.x;
        p.y = this->y + other.y;
        p.z = this->z + other.z;
        return p;
    }

    friend ostream &operator<<(ostream &output, const Point &p)
    {
        output << "(" << p.x << ", " << p.y << ")";
        return output;
    }

    friend ostream &operator+(ostream &output, const Point &p)
    {
        Point p;
        p.x = this->x + other.x;
        p.y = this->y + other.y;
        p.z = this->z + other.z;
    }
};

class Vector
{
private:
    Point start;
    Point end;

public:
    Vector() {}
    Vector(Point s, Point e)
        : start(s), end(e) {}

    Vector Add(Vector other)
    {
        Vector v;
        v.start = start + other.start;
        return v;
    }

    Vector &operator+(Vector &other)
    {
        start_x += other.start_x;
        start_y += other.start_y;
        end_x += other.end_x;
        end_y += other.end_y;
        return *this;
    }

    friend ostream &operator<<(ostream &output, const Vector &v)
    {
        output << "(" << v.start_x << ", " << v.start_y << ")"
               << " ---> "
               << "(" << v.end_x << ", " << v.end_y << ")";
        return output;
    }
};

int main()
{
    Point p1(1, 1), p2(2, 5);

    Vector v1(1, 1, 5, 5), v2(2, 2, 6, 6);

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;

    Vector v3 = v1.Add(v2);
    cout << "v3: " << v3 << endl;

    Vector v4 = v1 + v2;
    cout << "v4: " << v4 << endl;

    return 0;
}