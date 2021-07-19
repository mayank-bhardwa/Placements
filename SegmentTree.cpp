#include <iostream>
#include <vector>
using namespace std;

int log(int n)
{
    // ceil(log2(n)) equivalent
    return 32 - __builtin_clz(n) - 1;
}

struct SegmentTree
{
private:
    int size;
    vector<long long> sums;

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            sums[x] = v;
            return;
        }

        int m = (lx + rx) / 2;

        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);

        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    long long get(int l, int r, int x, int lx, int rx)
    {
        if (rx <= l || lx >= r)
            return 0;

        if (lx >= l && rx <= r)
            return sums[x];

        int m = (lx + rx) / 2;

        return get(l, r, 2 * x + 1, lx, m) + get(l, r, 2 * x + 2, m, rx);
    }

public:
    void init(int n)
    {
        size = 1 << log(n);
        if (size < n)
            size <<= 1;
        sums.assign((size << 1) - 1, 0LL);
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    int get(int l, int r)
    {
        return get(l, r, 0, 0, size);
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, v, o;
    cin >> n >> m;
    SegmentTree ST;
    ST.init(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v;
        ST.set(i, v);
    }

    int l, r;
    while (m--)
    {
        cin >> o >> l >> r;
        if (o == 1)
            ST.set(l, r);
        else
            cout << ST.get(l, r) << endl;
    }

    return 0;
}