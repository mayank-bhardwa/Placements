#include <iostream>
#include <vector>
using namespace std;
enum color
{
    white,
    blue,
    black
};
bool helper(int u, vector<vector<int>> &g, vector<color> &visited)
{
    visited[u] = blue;

    for (auto i : g[u])
    {
        if (visited[i] == white && helper(i, g, visited))
            return false;

        if (visited[i] == blue)
            return true;
    }

    visited[u] = black;
    return false;
}

bool isCyclic(vector<vector<int>> &g, int n)
{
    vector<color> visited(n, white);

    for (auto i = 0; i < n; i++)
    {
        if (!visited[i] && helper(i, g, visited))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> g(4);
    g[0] = {1};
    g[1] = {2};
    // g[2] = {3};
    g[3] = {0};
    cout << (isCyclic(g, 4) ? "True" : "False");
    return 0;
}