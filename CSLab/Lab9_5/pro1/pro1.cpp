#include <iostream>

using namespace std;

int main()
{
    int num, i = 0;
    cin >> num;

    while (num != 0)
    {
        if (num % 2 == 0)
        {
            num = num / 2;
        }
        else
        {
            num -= 1;
        }
        i++;
    }

    cout << i << endl;

    return 0;
}
