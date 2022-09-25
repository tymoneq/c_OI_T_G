#include <bits/stdc++.h>

using namespace std;

int main()
{
    ofstream dane;
    dane.open("data.txt");
    dane << 100000 << " " << 100000 << "\n";
    for (int i = 0; i < 100000; i++)
        dane << 9;

    dane << "\n";
    for (int i = 0; i < 100000; i++)
        dane << 0;

    dane << "\n";

    for (int i = 0; i < 100000; i++)
        dane << "S " << 99999 << "\n";

    dane.close();
    return 0;
}