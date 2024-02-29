#include <iostream>
#include <string>

using namespace std;

void print_even(int *arr, int maxNum)
{
    int i;
    for (i = 0; i < maxNum; i++)
    {
        if (arr[i] == 0 && (i + 1 % 2 != 0))
        {
            cout << i + 1 << " ";
        }
    }
}

void print_odd(int *arr, int maxNum)
{
    int i;
    for (i = 0; i < maxNum; i++)
    {
        if (arr[i] == 0 && i + 1 % 2 == 0)
        {
            cout << i + 1 << "_ ";
        }
    }
}

int main()
{
    int numOfPrisoner = 0, i, maxNum = 0;
    cin >> numOfPrisoner;
    int prisoners[numOfPrisoner];

    for (i = 0; i < numOfPrisoner; i++)
    {
        cin >> prisoners[i];
        if (i == 0)
        {
            maxNum = prisoners[i];
        }

        if (prisoners[i] > maxNum)
        {
            maxNum = prisoners[i];
        }
    }

    int checkedPrisoners[maxNum];

    for (i = 0; i < numOfPrisoner; i++)
    {
        cout << prisoners[i] << " ";
    }
    cout << endl;

    for (i = 0; i < maxNum; i++)
    {
        for (int j = 0; j < numOfPrisoner; j++)
        {
            if (prisoners[j] == i + 1)
            {
                cout << "prisoners[j] = " << prisoners[j] << endl;
                checkedPrisoners[i] = 1;
                break;
            }
        }
        if (checkedPrisoners[i] != 1)
            checkedPrisoners[i] = 0;
    }
    cout << maxNum << endl;
    // print checkedPrisoners
    for (i = 0; i < maxNum; i++)
    {
        cout << checkedPrisoners[i] << " ";
    }
    return 0;
}
