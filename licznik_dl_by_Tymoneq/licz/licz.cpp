#include <bits/stdc++.h>

using namespace std;

int main()
{

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
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
            unsigned int index_more_than10 = 0;
            unsigned int index_less_than8 = 0;

            if (x == 1)
                suma = temp_dl_wew + temp_dl_zew;

            else
            {
                
                auto more = more_than_10.lower_bound(x);
                cout << "more " << *more  <<"\n";
                if (*more >= x)
                {
                    int j = 1;
                    cout << "more " << *more  <<"\n";
                    while (true)
                    {
                        auto more = more_than_10.lower_bound(x - j);
                        if ((*more < x))
                            break;
                        ++j;
                    }
                }
                auto less = less_than_8.lower_bound(x);
                cout << " less " << *less << "\n";
                if ((*less >= x))
                {
                    int j = 1;
                    cout << " less " << *less << "\n";
                    while (true)
                    {
                        auto less = less_than_8.lower_bound(x - j);
                        if ((*less < x))
                            break;
                        ++j;
                    }
                }
                cout << "more " << *more << " less " << *less << "\n";
                if ((*more > *less))
                {
                    suma = temp_dl_wew + temp_dl_zew + 1;
                }
                else if (*more < *less)
                {
                    suma = temp_dl_wew + temp_dl_zew;
                }
            }
            for (auto el : more_than_10)
            {
                cout << "more than 10 " << el << " ";
            }
            cout << "\n";
            for (auto el : less_than_8)
            {
                cout << "less than 8 " << el << " ";
            }
            cout << "\n";
            cout << "\n";
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