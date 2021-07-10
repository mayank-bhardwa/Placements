#include <iostream>
#include <vector>
using namespace std;

class DisjointSet
{
protected:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        while (parent[x] != x)
            x = parent[x];
        return x;
    }

    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);

        if (size[u] < size[v])
            swap(u, v);

        parent[v] = u;
        size[u] += size[v];
    }

    void print()
    {
        for (int i = 0; i < parent.size(); i++)
            cout << i << " " << parent[i] << " " << size[i] << "\n";
    }
};

int main(int argc, char const *argv[])
{
    DisjointSet ds(7);
    ds.merge(1, 6);
    ds.merge(0, 6);
    ds.merge(3, 4);
    ds.print();
    return 0;
}