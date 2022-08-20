#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    cout << min(min(x, w-x), min(y, h-y)) << '\n';
    return 0;
}
