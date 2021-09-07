#include <iostream>
#include <vector>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.length();
    int start = 0;
    int maxLength = 1;

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    dp[0][0] = true;

    for (int i = 1; i < n; i++)
    {
        dp[i][i] = true;
        if (s[i] == s[i - 1])
            dp[i][i - 1] = true;
    }

    for (int l = 3; l <= n; l++)
    {
        for (int i = 0; i < n - l + 1; i++)
        {
            int j = i + l - 1;

            if (s[j] == s[i] && dp[i + 1][j - 1])
            {
                dp[i][j] = true;
                if (l > maxLength)
                {
                    start = i;
                    maxLength = l;
                }
            }
        }
    }
    return s.substr(start, maxLength);
}

int main()
{
    string s;
    cin >> s;
    cout << longestPalindrome(s);
    return 0;
}