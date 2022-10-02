#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    unsigned int wynik = 0, droz, rog, pon, suma, div_3, mod_3, max_droz = 0, max_pon = 0, max_rog = 0;
    unsigned long long koszt_pt = 0;
    cin >> n;
    div_3 = n / 3;
    mod_3 = n / 3;
    vector<vector<int>> v(n);

    for (int i = 0; i < n; i++)
    {
        suma = 0;
        cin >> droz >> pon >> rog;
        suma = droz + pon + rog;

        koszt_pt += suma - max(max(droz, pon), rog);
        if (max(max(droz, pon), rog) == droz)
            max_droz += 1;
        if (max(max(droz, pon), rog) == pon)
            max_pon += 1;
        if (max(max(droz, pon), rog) == rog)
            max_rog += 1;
        v[i].push_back(droz);
        v[i].push_back(pon);
        v[i].push_back(rog);
    }
    cout << koszt_pt << "\n";
    // sprawdz czy max_droz, max_pon, max_rog > div_3 i dodaj do tego logikę
    return 0;
}