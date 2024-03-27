#include <iostream>
using namespace std;

class Transportation
{
public:
    virtual double fare() = 0;
};

class BmtaBus : public Transportation
{
    public:
    double fare()
    {
        return 6.50;
    }
};

class BTS : public Transportation
{

    private: 
        double fee;
    
    public:
    BTS(): fee(15.0) {}

    void setStation(int station)
    {
        fee += station * 5;
    }

    double fare()
    {
        return fee;
    }
};

int main()
{
    int tc;
    cin >> tc; 
    if (tc == 1)
    {
        BmtaBus bus; // Create an object of BmtaBus
        cout << "BMTA Bus fare: "
             << bus.fare() << endl;
    }
    else if (tc == 2)
    {
        BmtaBus bus; // Create an object of BmtaBus
        Transportation *transport = &bus; // Point to the object of BmtaBus
        cout << "Transporataion fare: "
             << transport->fare() << endl;
    }
}