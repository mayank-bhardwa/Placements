#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> arr)
{
    for(auto i : arr)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<"\n";
    }
}

int solve(int n, int m)
{
    vector<vector<int>> cache(n + 1,vector<int>(m + 1,0));
    cache[0][0] = -1;
    for (int i = 1; i <= n; i++)
        cache[i][0] = 1;
    for (int i = 1; i <= m; i++)
        cache[0][i] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cache[i][j] = cache[i - 1][j] + cache[i][j - 1];



    print(cache);
    return cache[n][m];
}

int main()
{
    freopen("input", "r", stdin);
    int n, m;
    cin >> n >> m;
    cout << solve(n, m);
    return 0;
}