#include <bits/stdc++.h>
//https://szkopul.edu.pl/problemset/problem/w3anjkOGa2eMEBt_-GYEosat/site/?key=statement
using namespace std;

int n, z;
map<int, pair<int, int>> mapka;

void vectorIntPrint(vector<int> &vector)
{
    if(!vector.size())
        return;
    for (int element : vector)
        cout << element << " ";
    cout << endl;
}

void dodawanie(vector<int> &a, vector<int> &b, vector<int> &wynik, int &indeks)
{
    for(int i = a.size()-1; i >= n-indeks; i--)
    {
        if(b[i] + a[i] + wynik[i] >= 10)
        {
            wynik[i] = (b[i] + a[i]+ wynik[i])%10;
            wynik[i-1] += 1;            
        }
        else
        {
            wynik[i] += (b[i] + a[i]);
        }
    }
}

void vis(string &s, string &s1, vector<int> &v, vector<int> &v1)
{
    for(int i = 1; i <= s.size(); i++)
    {
        int tmp = s[i-1];
        int tmp1 = s1[i-1];
        tmp -= 48;
        tmp1 -= 48;
        v[i] = tmp;
        v1[i] = tmp1;
        if(v[i] + v1[i] >= 10)
        {
            mapka[i] = pair<int, int>(v[i], v1[i]);
        }

    }
// for(auto itr = mapka.begin(); itr != mapka.end(); itr++)  //map<char, int>::iterator itr = mp.begin();
//     cout << (*itr).first << " " << (*itr).second.first << " " << itr->second.second <<endl;                   //(*itr).first === itr->first
}

int main()
{
    string dl_wew_in;
    string dl_zew_in;
    int indeks, c;
    cin >> n >> z;

    string dl_sum_in;
    dl_sum_in.resize(n);
    
    cin >> dl_wew_in >> dl_zew_in;

    vector<int> dl_wewnetrzy(n); 
    vector<int> dl_zewnetrzny(n); 

    vis(dl_wew_in, dl_zew_in, dl_wewnetrzy, dl_zewnetrzny);

// printf("\n\n");

    for(int i = 0; i < z; i++)
    {
        char wczytywanie;
        cin >> wczytywanie;
        if(wczytywanie == 'W')
        {
            cin >> indeks >> c;
            dl_wewnetrzy[n-indeks] = c;
            // cout << "wew: ";
            // vectorIntPrint(dl_wewnetrzy);
        }
        else if(wczytywanie == 'Z')
        {
            cin >> indeks >> c;
            dl_zewnetrzny[n-indeks] = c;
            // cout << "zew: ";
            // vectorIntPrint(dl_zewnetrzny);
        }
        else
        {
            vector<int> dl_sum(n); 
            int suma;
            cin >> indeks;
            if(indeks == 1)
            {
                suma = dl_wewnetrzy[n-indeks] + dl_zewnetrzny[n-indeks];
// cout << suma % 10 << " ind\n";
                cout << suma % 10 << "\n";
            }
            else
            {
                if(dl_wewnetrzy[n-indeks+1] + dl_zewnetrzny[n-indeks+1] >= 10)
                {
                    suma = dl_wewnetrzy[n-indeks] + dl_zewnetrzny[n-indeks] + 1;
                    // vectorIntPrint(dl_wewnetrzy);
                    // vectorIntPrint(dl_zewnetrzny);
                    // printf("%d : %d : %d : %d\n", suma%10, n-indeks, dl_wewnetrzy[n-indeks], dl_zewnetrzny[n-indeks]);
                    cout << suma % 10 << "\n";
                }
                else if(dl_wewnetrzy[n-indeks+1] + dl_zewnetrzny[n-indeks+1] <= 8)
                {
                    // vectorIntPrint(dl_wewnetrzy);
                    // vectorIntPrint(dl_zewnetrzny);
                    printf("%d\n", (dl_wewnetrzy[n-indeks] + dl_zewnetrzny[n-indeks])%10);

                }
                else
                {
                    auto itr = mapka.end();
                    itr--;
                    if((*itr).first > indeks)
                    {
                        printf("%d\n", (dl_wewnetrzy[n-indeks] + dl_zewnetrzny[n-indeks])%10);
                    }
                    else
                    {
                        dodawanie(dl_wewnetrzy, dl_zewnetrzny, dl_sum, indeks);
                        printf("%d\n", dl_sum[n-indeks]);
                    }
                }
            }
                
        }
    }

    return 0;
}