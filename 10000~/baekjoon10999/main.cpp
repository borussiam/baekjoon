#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1<<21;
ll N, M, K, seg[MAX], lazy[MAX], start = MAX / 2;

void propagate(int node, int ns, int ne)
{
    if(lazy[node] != 0){
        if(node < start){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        seg[node] += lazy[node] * (ne - ns);
        lazy[node] = 0;
    }
}

void add(int s, int e, int k, int node, int ns, int ne)
{
    propagate(node, ns, ne);
    if(e <= ns || ne <= s){
        return;
    }
    if(s <= ns && ne <= e){
        lazy[node] += k;
        propagate(node, ns, ne);
        return;
    }
    int mid = (ns + ne) / 2;
    add(s, e, k, node*2, ns, mid);
    add(s, e, k, node*2+1, mid, ne);
    seg[node] = seg[node*2] + seg[node*2+1];
}

ll sum(int s, int e, int node, int ns, int ne)
{
    propagate(node, ns, ne);
    if(e <= ns || ne <= s){
        return 0;
    }
    if(s <= ns && ne <= e){
        return seg[node];
    }
    int mid = (ns + ne) / 2;
    return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(seg, seg+MAX, 0);
    fill(lazy, lazy+MAX, 0);
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        cin >> seg[start+i];
    }
    for(int i = start-1; i > 0; i--){
        seg[i] = seg[i*2] + seg[i*2+1];
    }
    for(int i = 0, a, b, c; i < M+K; i++){
        cin >> a >> b >> c;
        if(a == 1){
            ll d; cin >> d;
            add(b-1, c, d, 1, 0, start);
        }
        else{
            cout << sum(b-1, c, 1, 0, start) << '\n';
        }
    }
    return 0;
}
