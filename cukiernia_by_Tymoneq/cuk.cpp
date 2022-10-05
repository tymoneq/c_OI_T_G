#include <bits/stdc++.h>

using namespace std;
bool sortcol(const vector<int> &v1, const vector<int> &v2)
{
    return v1[1] > v2[1];
}

bool sortcol2(const vector<int> &v1, const vector<int> &v2)
{
    return v1[2] > v2[2];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    unsigned int droz, rog, pon, trzy = 0, mod_3 = 0, suma = 0;
    long long koszt = 0, suma_pon = 0, suma_rog = 0, suma_droz = 0;
    cin >> n;

    trzy = n / 3;
    mod_3 = n % 3;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {

        cin >> droz >> pon >> rog;
        suma_droz += droz;
        suma_pon += pon;
        suma_rog += rog;
        v[i].push_back(droz);
        v[i].push_back(pon);
        v[i].push_back(rog);
    }

    // first column sort
    make_heap(v.begin(), v.end());
    for (int i = 0; i < trzy; i++)
    {
        if (suma_droz != 0)
        {
            suma_droz -= v[i][0];
            v.erase(v.begin());
        }
    }

    //  second column sort
    sort(v.begin(), v.end(), sortcol);
    for (int i = 0; i < trzy; i++)
    {
        if (suma_pon != 0)
        {
            suma_pon -= v[i][1];
            v.erase(v.begin());
        }
    }

    //  third column sort

    sort(v.begin(), v.end(), sortcol2);
    for (int i = 0; i < trzy; i++)
    {
        if (suma_rog != 0)
        {
            suma_rog -= v[i][2];
            v.erase(v.begin());
        }
    }
    for (int i = 0; i < mod_3; i++)
    {

        suma += max(max(v[i][0], v[i][1]), v[i][2]);
    }
    koszt = suma_droz + suma_pon + suma_rog - suma;
    cout << koszt << "\n";
    return 0;
}