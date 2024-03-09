#include <iostream>
#include <cmath>

using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time() : hour(0), minute(0), second(0) {}
    Time(int hour, int minute, int second) : hour(hour), minute(minute), second(second) {}
    Time(int duration)
    {
        hour = duration / 3600;
        minute = (duration % 3600) / 60;
        second = duration % 60;

        if (hour > 24)
        {
            hour = hour - 24;
        }
    }

    int getHour() { return hour; }
    void setHour(int hour) { this->hour = hour; }

    int getMinute() { return minute; }
    void setMinute(int minute) { this->minute = minute; }

    int getSecond() { return second; }
    void setSecond(int second) { this->second = second; }

    int getDuration()
    {
        return hour * 3600 + minute * 60 + second;
    }

    Time add(Time other)
    {
        int hour = this->hour + other.hour;
        int minute = this->minute + other.minute;
        if (minute >= 60)
        {
            hour++;
            minute -= 60;
        }

        int second = this->second + other.second;

        return Time(hour, minute, second);
    }

    int subtract(Time other)
    {
        int duration1 = this->getDuration();
        int duration2 = other.getDuration();
        int result = 0;
        if (duration1 > duration2)
        {
            result = duration1 - duration2;
        }
        else
        {
            result = (duration1 - duration2) + (24 * 3600);
        }

        return result;
    }

    int equals(Time other)
    {
        return this->getDuration() == other.getDuration();
    }

    string toString()
    {
        string result = sprintf("%02d:%02d:%02d", hour, minute, second);
        return result;
    }
};

int main()
{
    Time t1(2, 2, 2);
    Time t2(1, 1, 1);

    cout << "Duration: " << t1.getDuration() << " | " << t1.toString() << endl;
    cout << "Duration: " << t2.getDuration() << " | " << t2.toString() << endl;

    cout << "subtraction (1 - 2): " << t1.subtract(t2) << endl;
    cout << "subtraction (2 - 1): " << t2.subtract(t1) << endl;

    // delete t1;
    return 0;
}