#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll T, x1, y3, r1, x2, y2, r2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T--){
        cin >> x1 >> y3 >> r1 >> x2 >> y2 >> r2;
        ll d1 = (x2 - x1) * (x2 - x1) + (y2 - y3) * (y2 - y3);
        ll d2 = (r1 + r2) * (r1 + r2);
        ll d3 = (r1 - r2) * (r1 - r2);
        if(x1 == x2 && y3 == y2 && r1 == r2) cout << "-1\n";
        else if(d3 < d1 && d1 < d2) cout << "2\n";
        else if(d3 == d1 || d1 == d2) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}
