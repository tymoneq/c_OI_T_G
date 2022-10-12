#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, z;
    cin >> n >> m >> z;
    vector<int> G[n + 1];
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    return 0;
}