// użyj seta int  grafu z bfs dopisz nazwisko do maila
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, z;
    cin >> n >> m >> z;
    vector<pair<int, int>> G[n + 1];

    pair<int, int> street_num[n];

    for (int i = 1; i < n; i++)
    {

        int a, b, c;
        cin >> a >> b >> c;

        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
        street_num[i] = make_pair(a, b);
    }

    for (int i = 0; i < z; i++)
    {
        char oper;
        int city;
        cin >> oper >> city;
        if (oper == 'Z')
        {
            // bfs
            vector<set<int>> odl(n + 1);

            bool *visited = new bool[n + 1]{0};

            vector<int> q;
            q.push_back(1);
            visited[1] = true;

            for (int i = 0; i < q.size(); i++)
            {

                int a = q[i];

                for (auto b : G[a])
                {
                    if (!visited[b.first])
                    {
                        if (a != 1)
                            odl[b.first].insert(odl[a].begin(), odl[a].end());

                        odl[b.first].insert(b.second);
                        visited[b.first] = true;
                        q.push_back(b.first);
                    }
                }
                if (visited[city])
                    break;
            }
            cout << odl[city].size() << "\n";
        }
        else if (oper == 'B')
        {
            int biciak;
            cin >> biciak;

            int city_a = street_num[city].first;
            int city_b = street_num[city].second;

            vector<pair<int, int>> *pV = &G[city_a];
            for (auto el = pV->begin(); el != pV->end(); el++)
            {

                if (el->first == city_b)
                {
                    el->second = biciak;

                    break;
                }
            }

            pV = &G[city_b];
            for (auto el = pV->begin(); el != pV->end(); el++)
            {

                if (el->first == city_a)
                {
                    el->second = biciak;

                    break;
                }
            }
            
        }
    }

    return 0;
}