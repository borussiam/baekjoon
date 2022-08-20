#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAX_ST = 1<<18, MAX = 1e5;
ll N, M, P[MAX], A[MAX-1], B[MAX-1], C[MAX-1], price[MAX-1];
ll start = MAX_ST / 2, seg[MAX_ST], lazy[MAX_ST];

void propagate(int node, int ns, int ne)
{
    if(lazy[node] != 0){
        if(node < start){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        seg[node] += (ne - ns) * lazy[node];
        lazy[node] = 0;
    }
}

void pass(int s, int e, int node, int ns, int ne)
{
    if(s > e){
        pass(e, s, node, ns, ne);
        return;
    }
    propagate(node, ns, ne);
    if(e <= ns || ne <= s) return;
    if(s <= ns && ne <= e){
        lazy[node] += 1;
        propagate(node, ns, ne);
        return;
    }
    int mid = (ns + ne) / 2;
    pass(s, e, node*2, ns, mid);
    pass(s, e, node*2+1, mid, ne);
    seg[node] = seg[node*2] + seg[node*2+1];
}

void propagate_all(int node, int ns, int ne)
{
    propagate(node, ns, ne);
    if(node < start){
        int mid = (ns + ne) / 2;
        propagate_all(node*2, ns, mid);
        propagate_all(node*2+1, mid, ne);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(seg, seg+MAX_ST, 0);
    fill(lazy, lazy+MAX_ST, 0);
    cin >> N >> M;
    cin >> P[0];
    for(int i = 1; i < M; i++){
        cin >> P[i];
        pass(P[i-1]-1, P[i]-1, 1, 0, start);
    }
    propagate_all(1, 0, start);
    // for(int i = 0; i < N-1; i++){
    //     cout << get_val(i) << ' ';
    // }
    // return 0;
    ll ans = 0;
    for(int i = 0; i < N-1; i++){
        cin >> A[i] >> B[i] >> C[i];
        ll n_pass = seg[start+i];
        if(n_pass * A[i] < n_pass * B[i] + C[i]){
            ans += n_pass * A[i];
        }
        else{
            ans += n_pass * B[i] + C[i];
        }
    }
    cout << ans << '\n';
    return 0;
}
