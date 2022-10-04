#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    typedef unsigned long long ull;
    int n;
    unsigned int wynik = 0, d, r, p, suma, div_3, mod_3, max_droz = 0, max_pon = 0, max_rog = 0;
    multimap<unsigned int, pair<int, int>> map_of_pairs;

    cin >> n;
    div_3 = n / 3;
    mod_3 = n / 3;
    vector<vector<int>> v(n);
    vector<unsigned int> max_val(n);
    int tmp[n];
    bool hasValues[3];
    int maxValues[3][3];

    ull koszt_pt = 0;
    for (int i = 0; i < n; i++)
    {
        suma = 0;
        cin >> d >> r >> p;
        v[i].push_back(d);
        v[i].push_back(r);
        v[i].push_back(p);
        koszt_pt = d + r + p - max(max(d, r), p);
        max_val.push_back(max(max(d, r), p));
        hasValues[0] |= d != 0;
        hasValues[1] |= r != 0;
        hasValues[2] |= p != 0;
        tmp[i] = i;
    }

    for (int colIdx = 0; colIdx < 3; colIdx++)
    {
        // for (auto el : tmp)
        // {
        //     cout << el << " ";
        // }
        // cout << "\n";
        // cout << "\n";
        /* Sorting the array `tmp` in ascending order. */
        make_heap(tmp, tmp + n, [&](int &a, int &b)
                  { return max_val[a] - v[a][colIdx] > max_val[b] - v[b][colIdx]; });
        // for (auto el : tmp)
        // {
        //     cout << el << " ";
        // }
        // cout << "\n";
        // cout << "\n";
        for (int i = 0; i < 3; i++)
        {
            maxValues[colIdx][i] = tmp[i];
        }
    }
    ull minCost = numeric_limits<ull>::max();
    for (int dMaxIdx = 0; dMaxIdx < 3; dMaxIdx++)
    {
        for (int pMaxIdx = 0; pMaxIdx < 3; pMaxIdx++)
        {
            for (int rMaxIdx = 0; rMaxIdx < 3; rMaxIdx++)
            {
                int dRowId = maxValues[0][dMaxIdx];
                int pRowId = maxValues[1][pMaxIdx];
                int rRowId = maxValues[2][rMaxIdx];
                if (dRowId == pRowId || pRowId == rRowId || rRowId == dRowId)
                    continue;
                ull newCost = koszt_pt;
                if (hasValues[0])
                    newCost += max_val[dRowId] - v[dRowId][0];
                if (hasValues[1])
                    newCost += max_val[pRowId] - v[pRowId][1];
                if (hasValues[2])
                    newCost += max_val[rRowId] - v[rRowId][2];
                if (minCost > newCost)
                    minCost = newCost;
            }
        }
    }

    cout << minCost << "\n";

    return 0;
}