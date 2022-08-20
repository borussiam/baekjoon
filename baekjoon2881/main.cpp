#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    pair<int, int> xtree[N], ytree[N];
    for(int i = 0, X, Y; i < N; i++){
        cin >> X >> Y;
        xtree[i] = {X, Y};
        ytree[i] = {Y, X};
    }
    sort(xtree, xtree+N);
    sort(ytree, ytree+N);
    int P; cin >> P;
    while(P--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        ans += upper_bound(xtree, xtree+N, make_pair(x1, y2-1)) - lower_bound(xtree, xtree+N, make_pair(x1, y1));
        ans += upper_bound(ytree, ytree+N, make_pair(y2, x2-1)) - lower_bound(ytree, ytree+N, make_pair(y2, x1));
        ans += upper_bound(xtree, xtree+N, make_pair(x2, y2)) - lower_bound(xtree, xtree+N, make_pair(x2, y1+1));
        ans += upper_bound(ytree, ytree+N, make_pair(y1, x2)) - lower_bound(ytree, ytree+N, make_pair(y1, x1+1));
        cout << ans << '\n';
    }
    return 0;
}
