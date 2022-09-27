#include <bits/stdc++.h>
//https://szkopul.edu.pl/problemset/problem/w3anjkOGa2eMEBt_-GYEosat/site/?key=statement
using namespace std;

int n, z;

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
void vis(string &s, vector<int> &v)
{
    for(int i = 1; i <= s.size(); i++)
    {
        int tmp = s[i-1];
        tmp -= 48;
        v[i] = tmp;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string dl_wew_in;
    string dl_zew_in;
    int indeks, c;
    cin >> n >> z;

    string dl_sum_in;
    dl_sum_in.resize(n);
    
    cin >> dl_wew_in >> dl_zew_in;

    vector<int> dl_wewnetrzy(n); 
    vector<int> dl_zewnetrzny(n); 

    vis(dl_wew_in, dl_wewnetrzy);
    vis(dl_zew_in, dl_zewnetrzny);

    for(int i = 0; i < z; i++)
    {
        char wczytywanie;
        cin >> wczytywanie;
        if(wczytywanie == 'W')
        {
            cin >> indeks >> c;
            dl_wewnetrzy[n-indeks] = c;
        }
        else if(wczytywanie == 'Z')
        {
            cin >> indeks >> c;
            dl_zewnetrzny[n-indeks] = c;
        }
        else
        {
            vector<int> dl_sum(n); 
            int suma;
            cin >> indeks;
            dodawanie(dl_wewnetrzy, dl_zewnetrzny, dl_sum, indeks);
            printf("%d\n", dl_sum[n-indeks]);
        }
    }
    return 0;
}