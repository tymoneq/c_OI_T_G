#include <bits/stdc++.h>

using namespace std;

void print2d(vector<vector<int>> &tab)
{
    for (int i = 0; i < tab.size(); i++)
    {
        for (int j = 0; j < tab[i].size(); j++)
            cout << tab[i][j] << " ";
        cout << endl;
    }
}

void zmien(int x, int y, vector<vector<int>> &tab, int &rozmiar)
{
    // cout << *x << *y;
    if (tab[x][y] == 1)
        rozmiar -= 1;
    else
        ++rozmiar;
    // cout << ++tab[*x][*y] << '\n';
    tab[x][y] ^= 1;
    
    // cout << tab[*x][*y] << '\n';

    // delete x;/* Deleting the pointer `y` which is pointing to the memory location of `y1` or `y2` */

    // delete y;
}

int main()
{
    int n, m{0}, q;
    int x1, y1, x2, y2;
    cin >> n >> m >> q;
    vector<vector<int>> tab(n+1);
    for (int i = 0; i < n+1; i++)
    {
        tab[i].resize(m+1);
    }

    for (int i = 0; i < q; i++)
    {
        int rozmiar = 0;
        puts("");
        puts("");
        print2d(tab);
        puts("");

        cin >> x1 >> y1 >> x2 >> y2;
        zmien(x2, y2, tab, rozmiar);
        zmien(x1-1, y2, tab, rozmiar);
        zmien(x2, y1-1, tab, rozmiar);
        zmien(x1, y1-1, tab, rozmiar);

        print2d(tab);
        puts("");
        puts("");
        printf("%d\n", rozmiar);
    }
    // delete wsk;

    return 0;
}