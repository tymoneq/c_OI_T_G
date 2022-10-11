#include <bits/stdc++.h>
// propaguj spadanie
using namespace std;
// map<int, bool[100001]> Gaps;
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
            // Gaps[i][b] = 1;
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
            if (x == n)
            {
                cout << "Not done yet "
                     << "\n";
            }
            else
            {
                int wynik = 0;
                for (int j = 0; j < gaps[x].size(); j++)
                {
                    wynik = j;
                    int lower = gaps[x][j];
                    for (int k = x + 1; k <= n; k++)
                    {
                        auto p_lower = lower_bound(gaps[k].begin(), gaps[k].end(), lower);
                        lower = *p_lower;
                        if (p_lower == gaps[x + 1].end())
                        {
                            break;
                        }
                    }
                }
                cout << wynik << "\n";
            }
        }
    }
    return 0;
}