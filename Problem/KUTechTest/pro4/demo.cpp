#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Train
{
public:
    int m;                             // Number of seats in the train
    int t;                             // Time interval between train arrivals (in minutes)
    int s;                             // Number of stations
    vector<pair<int, int> > passengers; // List of passengers (station, arrival time)

    Train(int m, int t, int s)
    {
        this->m = m;
        this->t = t;
        this->s = s;
    }

    void addPassenger(int station, int arrivalTime)
    {
        passengers.push_back(make_pair(station, arrivalTime));
    }

};

int main()
{
    int m, t, s, n;
    cin >> m >> t >> s >> n;

    Train train(m, t, s);

    for (int i = 0; i < n; i++)
    {
        int station, destination, waitingTime;
        cin >> station >> destination >> waitingTime;
        train.addPassenger(station, waitingTime);
    }


    return 0;
}
