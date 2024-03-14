#include <iostream>
#include <string>

using namespace std;

void printArr(bool **arr, int n, string str)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int longestPalindrome(string str)
{
    int n = str.length();

    bool **twoArr = new bool *[n];

    for (int i = 0; i < n; i++)
    {
        twoArr[i] = new bool[n];
        twoArr[i][i] = true;
    }

    printArr(twoArr, n);

    int maxLength = 1;
    for (int l = 2; l <= n; l++)
    {
        for (int i = 0; i < n - l + 1; i++)
        {
            int j = i + l - 1;

            if (str[i] == str[j])
            {
                if (l == 2)
                {
                    twoArr[i][j] = true;
                }
                else
                {
                    twoArr[i][j] = twoArr[i + 1][j - 1];
                }

                if (twoArr[i][j] && l > maxLength)
                {
                    maxLength = l;
                }
            }
        }
    }

    return maxLength;
}

int main()
{
    string text = "";
    cin >> text;

    int longestLength = longestPalindrome(text);

    cout << longestLength << endl;

    return 0;
}
