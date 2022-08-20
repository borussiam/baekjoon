#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int x1, y1, x2, y2, n, ans = 0;
        cin >> x1 >> y1 >> x2 >> y2 >> n;
        for(int i = 0, x, y, c; i < n; i++){
            cin >> x >> y >> c;
            bool s, e;
            s = ((x - x1) * (x - x1) + (y - y1) * (y - y1) < c * c);
            e = ((x - x2) * (x - x2) + (y - y2) * (y - y2) < c * c);
            ans += s ^ e;
        }
        cout << ans << '\n';
    }
    return 0;
}
