#include <iostream>
using namespace std;

class Players
{
public:
    Players(int x1, int y1, int z1)
        : x(x1), y(y1), z(z1) {}
    int M1()
    {
        return y;
    }
    virtual int M2()
    {
        return z;
    }
    int x;

protected:
    int y;

private:
    int z;
};

class B : public Players
{
public:
    B():Players(0,2,1){}

    int M2()
    {
        int z = Players::M2();
        if (z > 0)
            return z;
        else
            return (x + y);
    }

    int M3()
    {
        return x + y;
    }
};

int main(int argc, char const *argv[])
{
    Players p(10, 1, 2);

    B b;
    cout << b.M2() << endl;

    return 0;
}

