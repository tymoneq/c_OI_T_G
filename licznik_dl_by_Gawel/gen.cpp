#include<bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(NULL));

    int n = rand() % 50 + 1;
    int z = rand() % 50 + 1;
    printf("%d %d\n", n, z);

    for(int i = 0; i < n-1; i++)
    {
        int x = rand() % 10;
        cout << x;
    }
    puts("");

    for(int i = 0; i < n-1; i++)
    {
        int x = rand() % 10;
        cout << x;
    }
    puts("");

    for(int i = 0; i < z; i++)
    {
        int x = rand() % 3;
        int indeks = rand() % (n-1) + 1;
        int c = rand() % 10;
        switch (x)
        {
        case 0:
            cout << "W " << indeks << " " << c;
            break;
        case 1:
            cout << "Z " << indeks << " " << c;
            break;

        case 2:
            cout << "S " << indeks;
            break;
        default:
            break;
        }
        puts("");
    }


    return 0;
}