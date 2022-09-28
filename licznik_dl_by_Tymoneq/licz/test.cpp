#include <bits/stdc++.h>

using namespace std;

int main()
{

    int x;
    cin >> x;
    set<int> s{11, 22, 333, 555, 666};
    auto y = s.upper_bound(x);
    cout <<(*y) <<"\n";
    return 0;
}