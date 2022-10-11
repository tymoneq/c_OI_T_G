#include <bits/stdc++.h>
// propaguj spadanie
using namespace std;
map<int, bool[100001]> Gaps;
map<int, vector<int>> gaps;
int main()
{
    int n, X, z;
    cin >> n >> X >> z;

    // wczytanie danych do mapy
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            int b;
            cin >> b;
            gaps[i].push_back(b);
            Gaps[i][b] = 1;
        }
    }

    for (int i = 0; i < z; i++)
    {

        int x, min_oper = numeric_limits<int>::max();
        cin >> x;
        if (gaps[x].empty())
            cout << 0 << "\n";

        else
        {
            for (int j = 0; j < gaps[x].size(); j++)
            {
                int first_gap = gaps[x][j];
                for (int k = 0;)
            }
        }
    }
    return 0;
}