#include <bits/stdc++.h>

using namespace std;

void vectorIntPrint(vector<int> &vector)
{
    if (!vector.size())
        return;
    for (int element : vector)
        cout << element << " ";
    cout << endl;
}

bool tab[100000000];

void sito(int const &n)
{
    // int n = 10000;
    // cin >> n;
    vector<int> se;

    for (int i = 2; i * i <= n; i++)
    {
        if (tab[i] == 0)
            for (int j = i * i; j <= n; j += i)
                tab[j] = true;
    }

    for (int i = 2; i <= n; i++)
        if (tab[i] == 0)
            se.push_back(i);
    vectorIntPrint(se);
}