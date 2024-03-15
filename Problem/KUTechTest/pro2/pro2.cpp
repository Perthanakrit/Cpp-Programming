#include <iostream>
#include <string>

using namespace std;

void printArr(bool **arr, int n, string str)
{
    cout << "  ";
    for (int i = 0; i < n; i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << str[i] << " ";
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int longestPalindrome(string str)
{
    int n = str.length();

    bool **twoArr = new bool *[n];

    //--- soucre: gemini ----
    // substring of length 1 is palindrome
    for (int i = 0; i < n; i++)
    {
        twoArr[i] = new bool[n];
        twoArr[i][i] = true;
    }

    // find the longest substring of length 2 to n
    int maxLength = 1;
    for (int l = 2; l <= n; l++)
    {

        for (int i = 0; i < n - l + 1; i++)
        {
            int j = i + l - 1;

            // Check if the substring of length 2 to n is palindrome
            if (str[i] == str[j])
            {
                if (l == 2)
                {
                    twoArr[i][j] = true; // if length is 2, then it is palindrome
                }
                else
                {
                    twoArr[i][j] = twoArr[i + 1][j - 1]; //
                }

                // update the maxLength if the current length is greater than the previous maxLength
                if (twoArr[i][j] && l > maxLength)
                {
                    maxLength = l;
                }
            }
        }
    }

    //--- soucre: gemini ----

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
