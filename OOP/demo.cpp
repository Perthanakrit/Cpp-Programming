#include <iostream>
using namespace std;

class Car
{
private:
    int power;

public:
    Car(string name = "Car")
    {
        power = 100;
    }

    void Drive(int d)
    {
        power -= d;
    }

    int getPower() const
    {
        return power;
    }
};

int main()
{
    Car *c1 = new Car();
    Car c2("BMW");
    Car *c3 = c1; //
    Car &c4 = c2; //

    c2.Drive(10); // c4.Drive(10);
    c3->Drive(5); // c1->Drive(5);

    cout << c1->getPower() << endl;
    cout << c2.getPower() << endl;
    cout << c3->getPower() << endl;
    cout << c4.getPower() << endl;

    return 0;
}
