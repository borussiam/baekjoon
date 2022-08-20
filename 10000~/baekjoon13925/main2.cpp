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

const int MAX = 1e5+5, MAX_ST = 1<<19, start = 1<<18;
const ll MOD = 1e9+7;
ll N, M, q, x, y, v, ans, seg[MAX_ST];
pl lazy[MAX_ST];

void propagate(int node, int ns, int ne)
{
    if(!(lazy[node].fi == 1 && lazy[node].se == 0)){
        if(node < start){
            lazy[node*2].fi = (lazy[node*2].fi * lazy[node].fi) % MOD;
            lazy[node*2].se = (lazy[node*2].se * lazy[node].fi) % MOD;
            lazy[node*2].se = (lazy[node*2].se + lazy[node].se) % MOD;
            lazy[node*2+1].fi = (lazy[node*2+1].fi * lazy[node].fi) % MOD;
            lazy[node*2+1].se = (lazy[node*2+1].se * lazy[node].fi) % MOD;
            lazy[node*2+1].se = (lazy[node*2+1].se + lazy[node].se) % MOD;
        }
        seg[node] = (seg[node] * lazy[node].fi) % MOD;
        seg[node] = (seg[node] + lazy[node].se * (ne-ns)) % MOD;
        lazy[node].fi = 1;
        lazy[node].se = 0;
    }
}

void mod(int s, int e, ll v1, ll v2, int node, int ns, int ne)
{
    propagate(node, ns, ne);
    if(e <= ns || ne <= s) return;
    if(s <= ns && ne <= e){
        lazy[node].fi = (lazy[node].fi * v1) % MOD;
        lazy[node].se = (lazy[node].se + v2) % MOD;
        propagate(node, ns, ne);
        return;
    }
    int mid = (ns + ne) / 2;
    mod(s, e, v1, v2, node*2, ns, mid);
    mod(s, e, v1, v2, node*2+1, mid, ne);
    seg[node] = (seg[node*2] + seg[node*2+1]) % MOD;
}

ll sum(int s, int e, int node, int ns, int ne)
{
    propagate(node, ns, ne);
    if(e <= ns || ne <= s) return 0;
    if(s <= ns && ne <= e) return seg[node];
    int mid = (ns + ne) / 2;
    return (sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne)) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> seg[start+i];
    for(int i = start-1; i > 0; i--){
        seg[i] = (seg[i*2] + seg[i*2+1]) % MOD;
    }
    fill(lazy, lazy+MAX_ST, make_pair(1ll, 0ll));
    cin >> M;
    while(M--){
        cin >> q >> x >> y;
        if(q == 4){
            ans = sum(x-1, y, 1, 0, start);
            cout << ans << '\n';
            continue;
        }
        cin >> v;
        if(q == 1) mod(x-1, y, 1, v, 1, 0, start);
        else if(q == 2) mod(x-1, y, v, 0, 1, 0, start);
        else mod(x-1, y, 0, v, 1, 0, start);
    }
    return 0;
}
