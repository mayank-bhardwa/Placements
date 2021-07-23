#include <bits/stdc++.h>
using namespace std;

string pushDominoes(string dominoes)
{
    int n = dominoes.length();
    int arr[n];
    memset(arr, sizeof(arr), 0);
    for (int i : arr)
        cout << i << " ";

    int f = 0;
    for (int i = 0; i < n; i++)
    {
        if (dominoes[i] == 'R')
            f = n;
        else if (dominoes[i] == 'L')
            f = 0;
        else
            f--;

        arr[i] += f;
    }

    f = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (dominoes[i] == 'L')
            f = n;
        else if (dominoes[i] == 'R')
            f = 0;
        else
            f--;

        arr[i] -= f;
    }

    string res = "";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            res.append(".");
        else if (arr[i] < 0)
            res.append("L");
        else
            res.append("R");
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string dominoes;
    cin >> dominoes;
    cout << pushDominoes(dominoes);
    return 0;
}