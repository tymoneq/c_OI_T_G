#include <bits/stdc++.h>
// propaguj spadanie
using namespace std;

map<int, vector<int>> gaps;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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
        }
    }

    for (int i = 0; i < z; i++)
    {

        int x;
        cin >> x;
        if (gaps[x].empty())
            cout << 0 << "\n";

        else
        {
            if (x == n)
            {
                if (gaps[x].size() == 1)
                {
                    cout << 1 << "\n";
                }
                else
                {
                    int max_oper = gaps[x].size();
                    int wynik = max_oper, temp = 0;
                    for (int j = 0; j < max_oper; j++)
                    {
                        int lower = gaps[x][j];
                        for (int k = x - 1; k > x - max_oper; k++)
                        {
                            auto p_lower = lower_bound(gaps[k].begin(), gaps[k].end(), lower);
                            p_lower--;
                            ++temp;
                            lower = *p_lower;
                            p_lower = lower_bound(gaps[k].begin(), gaps[k].end(), lower);
                            if (p_lower == gaps[k].end())
                            {
                                wynik = temp;
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                bool running = true;

                int wynik = 0;

                for (int j = 0; j < gaps[x].size(); j++)
                {
                    if (!running)
                        break;
                    wynik = j;

                    int lower = gaps[x][j];
                    for (int k = x + 1; k <= n; k++)
                    {
                        auto p_lower = lower_bound(gaps[k].begin(), gaps[k].end(), lower);
                        if (p_lower == gaps[k].end())
                        {
                            running = false;
                            break;
                        }
                        else if (p_lower == gaps[x + 1].end())
                        {
                            running = false;
                            break;
                        }
                        else
                        {
                            lower = *p_lower;
                        }
                    }
                }
                cout << wynik << "\n";
            }
        }
    }
    return 0;
}