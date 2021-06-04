#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector<int> value;
vector<bool> visited;

void dfsMax(int u, int &c)
{
    visited[u] = true;
    c += value[u];
    int t = c;
    for (auto i : g[u])
    {
        if (!visited[i])
        {
            dfsMax(i, c);
            c = max(c, t);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, k, u, v;
    cin >> n >> k;
    g = vector<vector<int>>(n + 1);
    value = vector<int>(n + 1);
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> value[i];
    }

    visited = vector<bool>(n + 1, false);
    int re = 0;
    dfsMax(1, re);

    cout << max(re + k, k);
    return 0;
}