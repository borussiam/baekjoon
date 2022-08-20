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

const int MAX = 1e5, MAX_ST = 1<<19;
int N, M, q, a, b, c, start = 1;
ll seg[MAX_ST], lazy[MAX_ST];

void propagate(int node, int ns, int ne)
{
    if(lazy[node]){
        if(node < start){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        seg[node] += lazy[node] * (ne - ns);
        lazy[node] = 0;
    }
}

void add(int s, int e, int x, int node, int ns, int ne)
{
    propagate(node, ns, ne);
    if(e <= ns || ne <= s) return;
    if(s <= ns && ne <= e){
        lazy[node] += x;
        propagate(node, ns, ne);
        return;
    }
    int mid = (ns + ne) / 2;
    add(s, e, x, node*2, ns, mid);
    add(s, e, x, node*2+1, mid, ne);
    seg[node] = seg[node*2] + seg[node*2+1];
}

void print(int loc, int node, int ns, int ne)
{
    propagate(node, ns, ne);
    // printf("%d %d %d %d\n", loc, node, ns, ne);
    if(ne <= loc || loc+1 <= ns) return;
    if(ns == loc && loc+1 == ne){
        cout << seg[node] << '\n';
        return;
    }
    int mid = (ns + ne) / 2;
    print(loc, node*2, ns, mid);
    print(loc, node*2+1, mid, ne);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    while(start < N) start <<= 1;
    // cout << start << '\n';
    for(int i = 0; i < N; i++) cin >> seg[start+i];
    for(int i = start-1; i > 0; i--) seg[i] = seg[i*2] + seg[i*2+1];
    cin >> M;
    while(M--){
        cin >> q;
        if(q == 1){
            cin >> a >> b >> c;
            add(a-1, b, c, 1, 0, start);
            // for(int i = 1; i <= 2*start; i++) printf("%d ", seg[i]);
            // printf("\n");
            // for(int i = 1; i <= 2*start; i++) printf("%d ", lazy[i]);
            // printf("\n");
        }
        else{
            cin >> a;
            print(a-1, 1, 0, start);
        }
    }
    return 0;
}
