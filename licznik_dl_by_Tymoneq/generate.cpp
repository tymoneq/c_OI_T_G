#include <bits/stdc++.h>

using namespace std;

int main()
{
    ofstream dane;
    dane.open("data.txt");
    dane << 10 << " " << 100 << "\n";
    for (int i = 0; i < 10; i++)
        dane << 9;

    dane << "\n";
    for (int i = 0; i < 10; i++)
        dane << 0;

    dane << "\n";

    for (int i = 0; i < 1000000; i++)
        dane << "S " << 999999 - i << "\n";

    dane.close();
    return 0;
}