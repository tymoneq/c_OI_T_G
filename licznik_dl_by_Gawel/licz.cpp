#include <bits/stdc++.h>
//https://szkopul.edu.pl/problemset/problem/w3anjkOGa2eMEBt_-GYEosat/site/?key=statement
using namespace std;

int n, z;
set<int> bigger_than_10;
set<int> less_than_8;

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
            bigger_than_10.insert(i);
        }
        else if(v[i] + v1[i] <= 8)
        {
            less_than_8.insert(i);
        }

    }
// for(auto itr = mapka.begin(); itr != mapka.end(); itr++)  //map<char, int>::iterator itr = mp.begin();
    // cout << *itr <<endl;                   //(*itr).first === itr->first
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

    for(int i = 0; i < z; i++)
    {
        char wczytywanie;
        cin >> wczytywanie;
        if(wczytywanie == 'W')
        {
            cin >> indeks >> c;
            dl_wewnetrzy[n-indeks] = c;

            if(less_than_8.count(n-indeks) == 1)
                less_than_8.erase(n-indeks);

            if(bigger_than_10.count(n-indeks) == 1)
                bigger_than_10.erase(n-indeks);

            if(dl_zewnetrzny[n-indeks] + dl_wewnetrzy[n-indeks] >= 10)
            {
                bigger_than_10.insert(n-indeks);
            }
            if(dl_zewnetrzny[n-indeks] + dl_wewnetrzy[n-indeks] <= 8)
            {
                less_than_8.insert(n-indeks);
            }
            
            // for(auto itr = mapka.begin(); itr != mapka.end(); itr++)  //map<char, int>::iterator itr = mp.begin();
                // cout << (*itr).first << " " << (*itr).second.first << " " << itr->second.second <<endl;
            // if()
            // cout << "wew: ";
            // vectorIntPrint(dl_wewnetrzy);
        }
        else if(wczytywanie == 'Z')
        {
            cin >> indeks >> c;
            dl_zewnetrzny[n-indeks] = c;

            if(less_than_8.count(n-indeks) == 1)
                less_than_8.erase(n-indeks);

            if(bigger_than_10.count(n-indeks) == 1)
                bigger_than_10.erase(n-indeks);

            if(dl_zewnetrzny[n-indeks] + dl_wewnetrzy[n-indeks] >= 10)
            {
                bigger_than_10.insert(n-indeks);
            }
            if(dl_zewnetrzny[n-indeks] + dl_wewnetrzy[n-indeks] <= 8)
            {
                less_than_8.insert(n-indeks);
            }

            // for(auto itr = mapka.begin(); itr != mapka.end(); itr++)  //map<char, int>::iterator itr = mp.begin();
                // cout << (*itr).first << " " << (*itr).second.first << " " << itr->second.second <<endl;
        }
        else    //! liczenie
        {
            int suma{0};
            unsigned int index_more_than10 = 0;
            unsigned int index_less_than8 = 0;

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
                else     //todo jeśli poprzednie == 9
                {   
                    
                    auto less = less_than_8.lower_bound(n-indeks);
                    auto more = bigger_than_10.lower_bound(n-indeks);
                    int first10, first8;
                    bool czy10 = true;
                    bool czy8 = true;
                    if(more == bigger_than_10.end())
                    {
                        czy10 = false;
                        first10 = n+1;
                    }
                    else
                        first10 = *more;

                    if(less == less_than_8.end())
                    {
                        czy8 = false;
                        first8 = n+1;
                    }
                    else
                        first8 = *less;

                    if(*more == n-indeks && czy10)
                    {
                        more++;
                        first10 = *more;
                    }
                    if(*less == n-indeks && czy8)
                    {
                        less++;
                        first8 = *less;
                    }

                    if(more == bigger_than_10.end())
                    {
                        first10 = n+1;
                    }
                    else
                        first10 = *more;

                    if(less == less_than_8.end() )
                    {
                        first8 = n+1;
                    }
                    else
                        first8 = *less;


                    
                    
                    if(first8 > first10)
                    {
                        printf("%d\n", ((dl_wewnetrzy[n-indeks] + dl_zewnetrzny[n-indeks])+1)%10);//!
                    }
                    else
                    {
                        printf("%d\n", (dl_wewnetrzy[n-indeks] + dl_zewnetrzny[n-indeks])%10);//!
                    }
                   
                    
                }
            }
                
        }
    }
    return 0;
}