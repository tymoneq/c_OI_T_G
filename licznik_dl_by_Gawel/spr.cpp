#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream brut;
    ifstream licz;
    brut.open("brut.txt");
    licz.open("licz.txt");

    int b, l;
    int i = 0;
    while (brut >> b && licz >> l)
    {
        if(b != l)
        {
            cout << ++i << " - error\n";
        }
        else
            cout << ++i << " - OK\n";
    }
    brut.close();
    licz.close();

    return 0;
}