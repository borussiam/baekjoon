#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int MAX = 1e5, MAX_ST = 1<<18, start = 1<<17;
const ll MOD = 1e9+7;
ll N, M, A[MAX], seg[MAX_ST];
pii lazy[MAX_ST];

void propagate(int node, int ns, int ne)
{
    if(lazy[node] != make_pair(1ll, 0ll)){
        if(node < start){
            // if(lazy[node].first == 0){
            //     lazy[node*2] = {0, lazy[node].second};
            //     lazy[node*2+1] = {0, lazy[node].second};
            // }
            // else if(lazy[node].second == 0){
            //     lazy[node*2] = {(lazy[node].first*lazy[node*2].first) % MOD, (lazy[node].first*lazy[node*2].second) % MOD};
            //     lazy[node*2+1] = {(lazy[node].first*lazy[node*2+1].first) % MOD, (lazy[node].first*lazy[node*2+1].second) % MOD};
            // }
            // else{
                lazy[node*2] = {(lazy[node*2].first*lazy[node].first) % MOD, ((lazy[node*2].second*lazy[node].first)%MOD+lazy[node].second) % MOD};
                lazy[node*2+1] = {(lazy[node*2+1].first*lazy[node].first) % MOD, ((lazy[node*2+1].second*lazy[node].first)%MOD+lazy[node].second) % MOD};
            // }
            seg[node] = (((seg[node*2]*lazy[node*2].first)%MOD + lazy[node*2].second)%MOD + ((seg[node*2+1]*lazy[node*2+1].first)%MOD + lazy[node*2+1].second)%MOD) % MOD;
        }
        else{
            seg[node] = ((seg[node]*lazy[node].first)%MOD + lazy[node].second) % MOD;
        }
        lazy[node] = {1ll, 0ll};
    }
}

void mod(int s, int e, ll v1, ll v2, int node, int ns, int ne)
{
    propagate(node, ns, ne);
    if(e <= ns || ne <= s) return;
    if(s <= ns && ne <= e){
        lazy[node].first = (lazy[node].first*v1) % MOD;
        lazy[node].second = (lazy[node].second*v1 + v2) % MOD;
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
    fill(seg, seg+MAX_ST, 0);
    fill(lazy, lazy+MAX_ST, make_pair(1, 0));
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> seg[start+i];
    }
    for(int i = start-1; i > 0; i--){
        seg[i] = (seg[i*2] + seg[i*2+1]) % MOD;
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        int q, x, y, v;
        cin >> q >> x >> y;
        if(q == 4){
            cout << sum(x-1, y, 1, 0, start) << '\n';
            continue;
        }
        cin >> v;
        if(q == 1){
            mod(x-1, y, 1, v, 1, 0, start);
        }
        else if(q == 2){
            mod(x-1, y, v, 0, 1, 0, start);
        }
        else{
            mod(x-1, y, 0, v, 1, 0, start);
        }
    }
    return 0;
}
