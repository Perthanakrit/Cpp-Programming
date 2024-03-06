#include <iostream>
using namespace std;

class Taxable
{
public:
    virtual float getTax(float price) = 0;
};

class ThailandTax : public Taxable
{
public:
    float getTax(float price)
    {
        return price * 0.07;
    }
};

class USATax : public Taxable
{
public:
    float getTax(float price)
    {
        return price * 0.10;
    }
};

class ChinaTax : public Taxable
{
public:
    float getTax(float price)
    {
        if (price > 100)
        {
            return price * 0.05;
        }
        return 0;
    }
};

class CashRegister
{
private:
    float total;
    Taxable *tax;

public:
    CashRegister(Taxable *tax)
    {
        this->tax = tax;
    }

    void addItem(float price)
    {
        total += price;
    }

    float getTotalPrice() { return total; }

    float getNetPrice()
    {
        return total + (tax->getTax(total));
    }
};

int main(int argc, char const *argv[])
{
    CashRegister *cashRegister = new CashRegister(new ChinaTax());

    cashRegister->addItem(101);

    cout << cashRegister->getTotalPrice() << endl;
    cout << cashRegister->getNetPrice() << endl;

    return 0;
}
