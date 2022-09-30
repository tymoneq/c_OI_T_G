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
    unsigned int wynik = 0, koszt_pt = 0, droz, rog, pon;
    cin >> n;
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
    for (auto el : v)
    {
        cout << el[0] << " " << el[1] << " " << el[2] << "\n";
        if (el[0] > el[1] + el[2])
            koszt_pt -= el[0];

        else
        {

            break;
        }
    }
    cout << endl;
    // second column sort
    sort(v.begin(), v.end(), sortcol);
    for (auto el : v)
    {
        cout << el[0] << " " << el[1] << " " << el[2] << "\n";
        if (el[1] >= el[0] + el[2])
            koszt_pt -= el[1];

        else
        {

            break;
        }
    }
    cout << endl;
    // third column sort

    sort(v.begin(), v.end(), sortcol2);
    for (auto el : v)
    {
        cout << el[0] << " " << el[1] << " " << el[2] << "\n";
        if (el[2] >= el[0] + el[1])
            koszt_pt -= el[2];

        else
        {

            break;
        }
    }
    cout << koszt_pt << "\n";
    return 0;
}