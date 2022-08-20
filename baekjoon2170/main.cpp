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

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<pi> v;
    for(int i = 0, s, e; i < N; i++){
        cin >> s >> e;
        v.pb({s, e});
    }
    ll ans = 0;
    sort(v.begin(), v.end());
    int l = -INF, r = -INF;
    for(int i = 0; i < N; i++){
        if(r < v[i].fi){
            ans += r-l;
            l = v[i].fi;
            r = v[i].se;
        }
        else r = max(r, v[i].se);
    }
    ans += r-l;
    cout << ans << '\n';
    return 0;
}
