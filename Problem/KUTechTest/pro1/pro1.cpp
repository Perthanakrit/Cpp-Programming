#include <iostream>
using namespace std;

void sortingArr(int *arr, int size);
float medianInOddArr(int *arr, int size);
float medianInEvenArr(int *arr, int size);

int main()
{
    int n, i;
    cin >> n;
    int arr[n];

    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sortingArr(arr, n);

    if (n % 2 == 0)
    {
        printf("%.1f\n", medianInEvenArr(arr, n));
    }
    else
    {
        printf("%.1f\n", medianInOddArr(arr, n));
    }

    return 0;
}

void sortingArr(int *arr, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

float medianInOddArr(int *arr, int size)
{
    int pos = (size + 1) / 2 - 1;
    return (float)arr[pos];
}

float medianInEvenArr(int *arr, int size)
{
    int pos1 = (size / 2) - 1;
    int pos2 = (size / 2 + 1) - 1;

    return (arr[pos1] + arr[pos2]) / 2.0f;
}