#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string dl_wew{}, dl_zew{};

    char y{};
    unsigned int n{}, z{};
    set<unsigned int> more_than_10;
    set<unsigned int> less_than_8;

    cin >> n >> z;
    cin >> dl_wew >> dl_zew;

    for (int i = 0; i < n - 1; i++)
    {
        unsigned int suma = 0;
        unsigned int temp_1 = dl_wew[i] - 48;
        unsigned int temp_2 = dl_zew[i] - 48;

        suma = temp_1 + temp_2;
        if (suma <= 8)
        {
            less_than_8.insert(n - 1 - i);
        }
        else if (suma >= 10)
        {
            more_than_10.insert(n - 1 - i);
        }
    }

    for (int i = 0; i < z; i++)
    {
        int x{};
        char operacja{};
        cin >> operacja >> x;

        if (operacja == 'S')
        {

            unsigned int suma{0};
            unsigned int temp_dl_wew = dl_wew[n - 1 - x] - 48;
            unsigned int temp_dl_zew = dl_zew[n - 1 - x] - 48;
            

            if (x == 1)
                suma = temp_dl_wew + temp_dl_zew;

            else
            {
                unsigned int first_10 = 0;
                unsigned int first_8 = 0;

                auto more = more_than_10.lower_bound(x);

                if (more == more_than_10.begin())
                    first_10 = 0;
                else if (more == more_than_10.end())
                {
                    more--;
                    first_10 = *more;
                }
                else
                {
                    more--;
                    first_10 = *more;
                }
                auto less = less_than_8.lower_bound(x);

                if (less == less_than_8.begin())
                    first_8 = 0;
                else if (less == less_than_8.end())
                {
                    less--;
                    first_8 = *less;
                }
                else
                {
                    less--;
                    first_8 = *less;
                }
                // cout << "more " << *more << " less " << *less << "\n";

                if ((first_10 > first_8))
                {
                    suma = temp_dl_wew + temp_dl_zew + 1;
                }
                else if ((first_10 < first_8))
                {
                    suma = temp_dl_wew + temp_dl_zew;
                }
                else if ((first_10 == 0) && (first_8 == 0))
                {
                    suma = temp_dl_wew + temp_dl_zew;
                }
            }

            cout << suma % 10 << "\n";
        }
        else if (operacja == 'W')
        {
            cin >> y;

            if (dl_wew[n - 1 - x] - 48 + dl_zew[n - 1 - x] - 48 >= 10)
                more_than_10.erase(x);

            else if (dl_wew[n - 1 - x] - 48 + dl_zew[n - 1 - x] - 48 <= 8)
                less_than_8.erase(x);

            dl_wew[n - 1 - x] = y;

            if (y - 48 + dl_zew[n - 1 - x] - 48 >= 10)
                more_than_10.insert(x);

            else if (y - 48 + dl_zew[n - 1 - x] - 48 <= 8)
                less_than_8.insert(x);
        }
        else if (operacja == 'Z')
        {
            cin >> y;

            if (dl_wew[n - 1 - x] - 48 + dl_zew[n - 1 - x] - 48 >= 10)
                more_than_10.erase(x);

            else if (dl_wew[n - 1 - x] - 48 + dl_zew[n - 1 - x] - 48 <= 8)
                less_than_8.erase(x);

            dl_zew[n - 1 - x] = y;

            if (dl_wew[n - 1 - x] - 48 + y - 48 >= 10)
                more_than_10.insert(x);

            else if (dl_wew[n - 1 - x] - 48 + y - 48 <= 8)
                less_than_8.insert(x);

            // for (auto el : more_than_10)
            // {
            //     cout << "more than 10 " << el << " ";
            // }
            // cout << "\n";
            // for (auto el : less_than_8)
            // {
            //     cout << "less than 8 " << el << " ";
            // }
            // cout << "\n";
            // cout << "\n";
        }
    }

    return 0;
}