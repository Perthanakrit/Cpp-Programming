#include <iostream>
#include <string>

using namespace std;

int longestPalindrome(string str)
{
    int n = str.length();

    bool twoArr[n][n]; // twoArr is a 2D array of size n*n

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++)
    {
        twoArr[i][i] = true;
    }

    // Find the longest palindrome starting from substrings of length 2
    int maxLength = 1;
    for (int l = 2; l <= n; l++)
    {
        for (int i = 0; i < n - l + 1; i++)
        {
            int j = i + l - 1;

            // Check if current substring is a palindrome
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
