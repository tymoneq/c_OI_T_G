// użyj seta int  grafu z dijkstrą dopisz nazwisko do maila
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, z;
    cin >> n >> m >> z;
    vector<vector<pair<int, int>>> G(n);
    vector<set<int>> set_table;

    for (size_t i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        auto k1 = make_pair(b, c);
        auto k2 = make_pair(a, c);
        G[a].push_back(k1);
        G[b].push_back(k2);
    }

    return 0;
}