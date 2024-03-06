#include <iostream>
using namespace std;

class Super
{
public:
    virtual void print() = 0;
};

class Sub : public Super
{
public:
    void print()
    {
        cout << "Sub" << endl;
    }

    void foo()
    {
    }
};

int main(int argc, char const *argv[])
{
    Super *s = new Super();
    s->print();
    return 0;
}
