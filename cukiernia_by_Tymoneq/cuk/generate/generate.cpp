#include <bits/stdc++.h>

using namespace std;

int main()
{
    ofstream file;
    file.open("data.txt");
    file << 300000 << "\n";
    for (int i = 0; i < 300000; i++)
    {
        file << 3 << " " << 2 << " " << 1 << "\n";
    }

    file.close();
    return 0;
}