#include <iostream>
#include <vector>
using namespace std;

int log(int n)
{
    return 32 - __builtin_clz(n) - 1;
}

struct SegmentTree
{
private:
    int size;
    vector<int> mini;

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            mini[x] = v;
            return;
        }

        int m = (lx + rx) / 2;

        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);

        mini[x] = min(mini[2 * x + 1], mini[2 * x + 2]);
    }

    int get(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l)
            return INT32_MAX;

        if (lx >= l && rx <= r)
            return mini[x];

        int m = (lx + rx) / 2;

        return min(get(l, r, 2 * x + 1, lx, m), get(l, r, 2 * x + 2, m, rx));
    }

public:
    void init(int n)
    {
        size = 1 << log(n);
        if (size < n)
            size <<= 1;

        mini.assign(2 * size - 1, INT32_MAX);
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
    int n, m;
    cin >> n >> m;
    int v;
    SegmentTree st;
    st.init(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        st.set(i, v);
    }
    int o, l, r;
    while (m--)
    {
        cin >> o >> l >> r;

        if (o == 1)
            st.set(l, r);
        else
            cout << st.get(l, r) << endl;
    }
    return 0;
}