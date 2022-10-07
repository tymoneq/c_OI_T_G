// użyj seta int  grafu z dijkstrą dopisz nazwisko do maila
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, z;
    cin >> n >> m >> z;
    vector<vector<pair<int, int>>> G(n);
    vector<set<int>> set_table;
    map<int, pair<int, int>> street_num;
    for (size_t i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        auto pair_1 = make_pair(b, c);
        auto pair_2 = make_pair(a, c);
        G[a].push_back(pair_1);
        G[b].push_back(pair_2);
        street_num.insert({i, make_pair(a, b)});
    }
    for (int i = 0; i < z; i++)
    {
        char oper;
        int city;
        cin >> oper >> city;
        if (oper == 'Z')
        {
            // dijkstra
        }
        else if (oper == 'B')
        {
            int biciak{};
            cin >> biciak;
            pair<int, int> it = street_num.at(city);
            int city_a = it.first;
            int city_b = it.second;
            auto itr1 = find(G.begin(), G.end(),city_a);
           
            
        }
    }

    return 0;
}