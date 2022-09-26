#include <bits/stdc++.h>

using namespace std;

char max(unsigned int &droz, unsigned int &pon, unsigned int &rog)
{
    unsigned int max = 0;
    char type;

    if (droz == pon == rog)
    {
        type = 'W';
        return type;
    }

    if (max < droz)
    {
        max = droz;
        type = 'D';
    }

    if (pon > max)
    {
        max = pon;
        type = 'P';
    }
    if (rog > max)
    {
        max = rog;
        type = 'R';
    }
    // if (droz == pon)
    // {
    //     type = 'N';
    // }
    // if (pon == rog)
    // {
    //     type = 'M';
    // }
    // if (droz == rog)
    // {
    //     type = 'B';
    // }

    return type;
}

int main()
{
    int n;
    unsigned int wynik = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        unsigned int droz = 0, pon = 0, rog = 0;
        char type;
        cin >> droz >> pon >> rog;
        type = max(droz, pon, rog);
        if (type == 'D')
        {
            wynik += pon + rog;
        }
        else if (type == 'P')
        {
            wynik += droz + rog;
        }
        else if (type == 'R')
        {
            wynik += droz + pon;
        }
        else if (type == 'W')
        {
            wynik += droz + pon;
        }
        else if (type == 'N')
        {
            wynik += pon + rog;
        }
        else if (type == 'M')
        {
            wynik += droz + rog;
        }
        else if (type == 'B')
        {
            wynik += rog + pon;
        }
        
        cout << type << "\n";
    }
    cout << wynik << "\n";

    return 0;
}