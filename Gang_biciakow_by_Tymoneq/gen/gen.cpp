#include <bits/stdc++.h>

using namespace std;

int main()
{
    ofstream file;
    file.open("data.txt");
    file << 100000 << " " << 150000 << " " << 150000 << "\n";
    for (int i = 2; i <= 100000; i++)
    {
        file << i << " " << i - 1 << " " << 1 << "\n";
    }
    // for (int i = 0; i < 150000; i++)
    // {
    //     file << "Z " << 100000 <<"\n";
    // }

    file.close();
    return 0;
}