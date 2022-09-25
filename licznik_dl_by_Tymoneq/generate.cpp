#include <bits/stdc++.h>

using namespace std;

int main()
{
    ofstream dane;
    dane.open("data.txt");
    dane << 10000000 << " " << 10000000 << "\n";
    for (int i = 0; i < 10000000; i++)
        dane << 9;

    dane << "\n";
    for (int i = 0; i < 10000000; i++)
        dane << 0;

    dane << "\n";

    for (int i = 0; i < 10000000; i++)
        dane << "S " << 9999999 - i << "\n";

    dane.close();
    return 0;
}