#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, X, z;
    cin >> n >> X >> z;
    vector<pair<int, int>> Gaps;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        Gaps.push_back(make_pair(i, b));
    }
    for (int i = 0; i < z; i++)
    {

        int x;
        cin >> x;
    }
    return 0;
}