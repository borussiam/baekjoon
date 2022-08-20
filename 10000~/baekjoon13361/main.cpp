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

const ll MAX = 2.5e5+2;
ll n, uf[MAX*2], sum[MAX*2], mx[MAX*2], ans = 0;
bool cycle[MAX*2];
vector<pl> v;
vector<ll> num;

int find(int a)
{
    if(uf[a] == a) return a;
    return uf[a] = find(uf[a]);
}

bool merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v) return false;
    sum[u] += sum[v];
    mx[u] = max(mx[u], mx[v]);
    uf[v] = u;
    cycle[u] = cycle[u] || cycle[v];
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        v.pb({a, b});
        num.pb(a); num.pb(b);
    }
    sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());
    // for(int i : num) cout << i << ' ';
    for(int i = 0; i < num.size(); i++){
        uf[i] = i;
        sum[i] = num[i];
        mx[i] = num[i];
        // cout << sum[i] << '\n';
    }
    for(auto &p : v){
        int x = lower_bound(num.begin(), num.end(), p.fi) - num.begin();
        int y = lower_bound(num.begin(), num.end(), p.se) - num.begin();
        if(!merge(x, y)){
            cycle[find(x)] = 1;
        }
        // cout << sum[find(x)] << ' ' << mx[find(x)] << '\n';
    }
    for(auto &p : v){
        ans += p.fi + p.se;
    }
    // cout << ans << '\n';
    for(int i = 0; i < num.size(); i++){
        // cout << find(i) << '\n';
        if(i != find(i)) continue;
        if(cycle[i]) ans -= sum[i];
        else ans -= sum[i] - mx[i];
    }
    cout << ans << '\n';
    return 0;
}
