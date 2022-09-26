#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    unsigned int wynik = 0, koszt_pt = 0, droz, rog, pon, suma = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        suma = 0;
        cin >> droz >> pon >> rog;
        suma = droz + pon + rog;
        koszt_pt += suma - max(max(droz,pon), rog);
        
    }
    cout << koszt_pt << "\n";

    return 0;
}