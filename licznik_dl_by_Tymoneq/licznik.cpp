#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string dl_wew{}, dl_zew{};
    string operacja{};
    char y{};
    unsigned int n{}, z{};
    bool long_string = false;
    bool zamiana = false;
    unsigned int indeks = 0;
    cin >> n >> z;
    cin >> dl_wew >> dl_zew;

    for (int i = 0; i < z; i++)
    {
        int x{};
        cin >> operacja >> x;
        if (operacja == "W")
        {
            cin >> y;
            dl_wew[n - 1 - x] = y;
            zamiana = true;
        }
        else if (operacja == "Z")
        {
            cin >> y;
            dl_zew[n - 1 - x] = y;
            zamiana = true;
        }
        else if (operacja == "S")
        {
            unsigned int suma{0};
            unsigned int temp_dl_wew = dl_wew[n - 1 - x] - 48;
            unsigned int temp_dl_zew = dl_zew[n - 1 - x] - 48;

            if (n - x == n - 1)
            {

                suma = temp_dl_wew + temp_dl_zew;
                cout << suma % 10 << "\n";
            }
            else
            {
                unsigned int temp_dl_wew_1 = dl_wew[n - x] - 48;
                unsigned int temp_dl_zew_1 = dl_zew[n - x] - 48;
                if (temp_dl_zew_1 + temp_dl_wew_1 >= 10)
                {
                    suma = temp_dl_wew + temp_dl_zew + 1;
                    long_string = false;
                    indeks = 0;
                }
                else if (temp_dl_zew_1 + temp_dl_wew_1 == 9)
                {
                    if (n - 1 >= n - x + 2)
                    {

                        bool test = false;

                        if ((long_string) && (x > indeks) && (!zamiana))
                        {
                            suma = temp_dl_wew + temp_dl_zew;
                        }
                        else
                        {
                            for (int j = n - x + 1; j < n - 1; j++)
                            {

                                unsigned int temp_1 = dl_wew[j] - 48;
                                unsigned int temp_2 = dl_zew[j] - 48;
                                if (temp_1 + temp_2 >= 10)
                                {

                                    suma = temp_dl_wew + temp_dl_zew + 1;
                                    long_string = true;
                                    indeks = x - j;
                                    test = true;
                                    break;
                                }
                                else if (temp_1 + temp_2 == 9)
                                {
                                    indeks = x - j;
                                    long_string = true;
                                    continue;
                                }

                                else if (temp_1 + temp_2 <= 8)
                                {
                                    test = true;
                                    long_string = true;
                                    indeks = x - j;
                                    suma = temp_dl_wew + temp_dl_zew;
                                    break;
                                }
                            }
                            if (!test)
                                suma = temp_dl_wew + temp_dl_zew;
                        }
                    }
                    else
                        suma = temp_dl_wew + temp_dl_zew;
                }
                else if (temp_dl_wew_1 + temp_dl_zew_1 <= 8)
                {
                    suma = temp_dl_wew + temp_dl_zew;
                    long_string = false;
                    indeks = 0;
                }
                cout << suma % 10 << '\n';
            }
        }
    }

    return 0;
}