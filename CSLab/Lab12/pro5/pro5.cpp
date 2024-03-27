
#include <iostream>
using namespace std;

class Transportation
{
public:
    virtual double fare() = 0;
};

/* 
- การคำนวณค่าใช้จ่ายในการใช้บริการรถแท็กซี่ จะเริ่มต้นที่ 35 บาท และเพิ่มขึ้นตามระยะทางกิโลเมตรละ 2 บาท
- method setDistance(double) ที่รับระยะทางหน่วยกิโลเมตร, มี method fare() ที่คืนค่า ค่าใช้จ่ายในการใช้บริการรถแท็กซี่
*/
class Taxi : public Transportation
{
    private:
        double fee;

    public:
        Taxi(): fee(35.0) {}

        double fare()
        {
            return fee;
        }

        void setDistance(double dist)
        {
            double include = 2.0;
            fee += dist * include;
        }
};

/*
- คำนวณค่าใช้จ่ายในการใช้บริการรถขสมก. ครั้งละ 6.50 บาท ผ่าน method fare()
*/
class BmtaBus : public Transportation
{   
    private:
        double fee = 6.50;
    public:
        double fare()
        {
            return fee;
        }
};

/*
- ค่าใช้จ่ายในการใช้บริการรถไฟฟ้าบีทีเอส จะเริ่มต้นที่ 15 บาท และเพิ่มขึ้นตามจำนวนสถานี สถานีละ 5 บาท
- มี method setStation(int) ที่รับจำนวนสถานีที่จะโดยสารไป, มี method fare() ที่คืนค่า ค่าใช้จ่ายในการใช้บริการรถไฟฟ้าบีทีเอส
*/
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

/*
- void addTransportation(Transportation &) ผู้โดยสารเลือกใช้บริการรถโดยสารแบบใดก็ได้จาก รถแท็กซี่ รถขสมก. หรือรถบีทีเอส และคำนวณค่าใช้จ่ายรวมในการโดยสารรถทุกแบบ
- double getTotalFare() คืนค่า ค่าใช้จ่ายรวมในการโดยสารรถทุกแบบ
*/
class Passenger
{
    private:
        double totalFare = 0.0;
    public:
        void addTransportation(Transportation &transportation)
        {
            totalFare += transportation.fare();
        }

        double getTotalFare()
        {
            return totalFare;
        }
};

int main()
{
    Passenger passenger; // Create an object of Passenger
    while (1)
    {
        char transportType;
        cin >> transportType;
        if (transportType == 'A')
        {
            Taxi *taxi = new Taxi(); // Create an object of Taxi
            double distance;
            cin >> distance;
            
            taxi->setDistance(distance);
            passenger.addTransportation(*taxi); // dereference the pointer to pass the object
        }
        else if (transportType == 'B')
        {
            BmtaBus *bus = new BmtaBus();

            passenger.addTransportation(*bus);
        }
        else if (transportType == 'C')
        {
            BTS *bts = new BTS();
            int station;
            cin >> station;

            bts->setStation(station);
            passenger.addTransportation(*bts);
        }
        else
        {
            break;
        }
    }
    cout << "Total Fare: " << passenger.getTotalFare() << endl;
}