#include <iostream>
#include <string>

using namespace std;

int main()
{
    double salary = 0, totalSalary = 0;
    int i;
    char message[100];
    string name;

    cin >> name;
    cin >> totalSalary;

    totalSalary *= 12;

    for (i = 0; i < 12; i++)
    {
        cin >> salary;
        totalSalary += 0.15 * salary;
    }

    sprintf(message, "%s %.2lf", name.c_str(), totalSalary);
    cout << message << endl;

    return 0;
}
