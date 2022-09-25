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
        }
        else if (operacja == "Z")
        {
            cin >> y;
            dl_zew[n - 1 - x] = y;
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
                }
                else if (temp_dl_zew_1 + temp_dl_wew_1 == 9)
                {
                    if (n - 1 >= n - x + 2)
                    {
                        bool test = false;
                        for (int j = n - 1 - x + 2; j < n - 1; j++)
                        {

                            unsigned int temp_1 = dl_wew[j] - 48;
                            unsigned int temp_2 = dl_zew[j] - 48;
                            if (temp_1 + temp_2 >= 10)
                            {

                                suma = temp_dl_wew + temp_dl_zew + 1;
                                test = true;
                                break;
                            }
                            else if (temp_1 + temp_2 == 9)

                                continue;

                            else if (temp_1 + temp_2 <= 8)
                            {
                                test = true;

                                suma = temp_dl_wew + temp_dl_zew;
                                break;
                            }
                        }
                        if (!test)
                        {

                            suma = temp_dl_wew + temp_dl_zew;
                        }
                    }
                    else
                    {

                        suma = temp_dl_wew + temp_dl_zew;
                    }
                }
                else if (temp_dl_wew_1 + temp_dl_zew_1 <= 8)
                {

                    suma = temp_dl_wew + temp_dl_zew;
                }

                cout << suma % 10 << '\n';
            }
        }
    }

    return 0;
}