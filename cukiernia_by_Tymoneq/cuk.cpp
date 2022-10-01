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
    unsigned int droz, rog, pon, a_range = 0, mod_3 = 0;
    unsigned long long koszt_pt = 0;
    cin >> n;

    a_range = n / 3;
    mod_3 = n % 3;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {

        cin >> droz >> pon >> rog;
        koszt_pt += droz + pon + rog;

        v[i].push_back(droz);
        v[i].push_back(pon);
        v[i].push_back(rog);
    }

    // first column sort
    make_heap(v.begin(), v.end());
    for (int i = 0; i < a_range; i++)
    {
        // if (v[i][1] == 0 && v[i][2] == 0)
        // {
        //     koszt_pt -= v[i][0];
        //     i -= 1;
        // }
        // else
            koszt_pt -= v[i][0];
    }

    //  second column sort
    sort(v.begin(), v.end(), sortcol);
    for (int i = 0; i < a_range; i++)
    {

        // if (v[i][0] == 0 && v[i][2] == 0)
        // {
        //     koszt_pt -= v[i][1];
        //     i -= 1;
        // }
        // else
            koszt_pt -= v[i][1];
    }

    //  third column sort

    sort(v.begin(), v.end(), sortcol2);
    for (int i = 0; i < a_range; i++)
    {

        // if (v[i][0] == 0 && v[i][1] == 0)
        // {
        //     koszt_pt -= v[i][2];
        //     i -= 1;
        // }
        // else
            koszt_pt -= v[i][2];
    }
    cout << koszt_pt << "\n";
    return 0;
}