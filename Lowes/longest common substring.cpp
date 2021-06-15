#include <iostream>
#include <vector>
using namespace std;

// int lcs(string a, string b, int n, int m, int c)
// {
//     if (n == -1 || m == -1)
//         return c;
//     int count = c;
//     if (a[n] == b[m])
//     {
//         count = max(count, lcs(a, b, n - 1, m - 1, c + 1));
//     }
//     else
//     {
//         count = max(count, max(lcs(a, b, n - 1, m, 0), lcs(a, b, n, m - 1, 0)));
//     }

//     return count;
// }

int lcs(string a, string b)
{
    int dp[a.size() + 1][b.size() + 1];
    int res = 0;
    for (int i = 0; i <= a.size(); i++)
    {
        for (int j = 0; j <= b.size(); j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = 0;

            res = max(res, dp[i][j]);
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string a, b;
    cin >> a >> b;
    cout << lcs(a, b) << "\n";
    return 0;
}
