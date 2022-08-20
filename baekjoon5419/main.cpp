#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
#define fi first
#define se second
#define pb push_back

const int MAX = 75000, MAX_ST = 1<<18, start = 1<<17;
int n;
ll seg[MAX_ST];

void update(int loc)
{
    loc += start;
    ++seg[loc];
    while(loc > 1){
        loc /= 2;
        seg[loc] = seg[loc*2] + seg[loc*2+1];
    }
}

int sum(int s, int e, int node, int ns, int ne)
{
    if(e <= ns || ne <= s) return 0;
    if(s <= ns && ne <= e) return seg[node];
    int mid = (ns + ne) / 2;
    return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--){
        fill(seg, seg+MAX_ST, 0);
        ll ans = 0;
        cin >> n;
        vector<pi> P(n);
        vector<int> y(n);
        for(int i = 0; i < n; i++){
            cin >> P[i].fi >> P[i].se;
            y[i] = P[i].se;
        }
        sort(y.begin(), y.end());
        y.resize(unique(y.begin(), y.end()) - y.begin());
        for(auto &p : P) p.se = -(lower_bound(y.begin(), y.end(), p.se) - y.begin());
        sort(P.begin(), P.end());
        // for(auto &p : P) printf("%d %d\n", p.fi, -p.se);
        for(auto &p : P){
            ans += sum(-p.se, MAX, 1, 0, start);
            update(-p.se);
        }
        cout << ans << '\n';
    }
    return 0;
}
