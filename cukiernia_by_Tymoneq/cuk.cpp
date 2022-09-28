#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    unsigned int wynik = 0, koszt_pt = 0, droz, rog, pon, suma = 0;
    cin >> n;
    vector<vector<int>> v(n);

    for (int i = 0; i < n; i++)
    {
        suma = 0;
        cin >> droz >> pon >> rog;
        suma = droz + pon + rog;
        koszt_pt += suma - max(max(droz, pon), rog);

        v[i].push_back(droz);
        v[i].push_back(pon);
        v[i].push_back(rog);
    }
    cout << koszt_pt << "\n";
    for (auto el : v)
    {
        cout << el[0] << " " << el[1] << " " << el[2] << "\n";
    }

    return 0;
}