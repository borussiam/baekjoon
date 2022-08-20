#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    pair<int, int> coord[n];
    for(int i = 0, x, y; i < n; i++){
        cin >> x >> y;
        coord[i].first = x;
        coord[i].second = y;
    }
    sort(coord, coord+n);
    for(int i = 0; i < n; i++){
        cout << coord[i].first << ' ' << coord[i].second << '\n';
    }
    return 0;
}
