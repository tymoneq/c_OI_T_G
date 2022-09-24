#include <bits/stdc++.h>
#include <limits>

using namespace std;

int main()
{
    int n, z, number;
    cin >> n >> z;
    
    std::cin.clear();
    std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );    

    int *dl_wew = new int[n - 1]();
    int *dl_zew = new int[n - 1]();
    int *suma_dl = new int[n - 1]();

    // int dl_wew[n - 1] = {0};
    // int dl_zew[n - 1] = {0};
    // int suma_dl[n - 1] = {0};

    cin >> number;
    //std::cin.clear();
    //std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
    
    for (int i = n - 1; i > 0; i--)
    {
        dl_wew[i] = number % 10;
        number /= 10;
    }

    cin >> number;
    //std::cin.clear();
    //std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
    
    for (int i = n - 1; i > 0; i--)
    {
        dl_zew[i] = number % 10;
        number /= 10;
        suma_dl[i] = dl_wew[i] + dl_zew[i];
    }
    for (int i = 0; i < z; i++)
    {
       
        char operacja{};
        int x{0}, y{0};
        cin >> operacja >> x;
        
        
        if (operacja == 'W')
        {
            cin >> y;
            

            dl_wew[n - x] = y;
            suma_dl[n - x] = dl_wew[n - x] + dl_zew[n - x];
        }
        else if (operacja == 'Z')
        {
            cin >> y;
            

            dl_zew[n - x] = y;
            suma_dl[n - x] = dl_wew[n - x] + dl_zew[n - x];
        }
        else if (operacja == 'S')
        {
            if (n - x == n - 1)
            {
                cout << suma_dl[n - x] % 10 << "\n";
            }
            else
            {
                if (suma_dl[n - x + 1] <= 8)
                {

                    cout << suma_dl[n - x] % 10 << "\n";
                }
                else if (suma_dl[n - x + 1] >= 10)
                {

                    cout << (suma_dl[n - x] + 1) % 10 << "\n";
                }

                else if (suma_dl[n - x + 1] == 9)
                {
                    bool test = false;
                    for (int j = n - x + 1; j < n; j++)
                    {
                        if (suma_dl[j] <= 8)
                        {
                            cout << suma_dl[n - x] % 10 << "\n";
                            test = true;
                            break;
                        }
                        else if (suma_dl[j] >= 10)
                        {

                            cout << (suma_dl[n - x] + 1) % 10 << "\n";
                            test = true;
                            break;
                        }
                        else
                        {

                            continue;
                        }
                    }
                    if (!test)
                    {

                        cout << suma_dl[n - x] % 10 << "\n";
                    }
                }
            }
        }
    }
    
    delete [] suma_dl;
    delete [] dl_wew;
    delete [] dl_zew;

    return 0;
}