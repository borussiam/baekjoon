#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX = 1e5, MAX_ST = 1<<18, start = 1<<17;
int root, cnt = 0, num_to_node[MAX], L[MAX], R[MAX];
ll N, M, seg[MAX_ST], lazy[MAX_ST];
vector<int> adj[MAX];

void build(int curr)
{
    num_to_node[curr] = L[curr] = R[curr] = cnt++;
    for(int next : adj[curr]){
        build(next);
        R[curr] = R[next];
    }
}

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

void add(int s, int e, int w, int node, int ns, int ne)
{
    propagate(node, ns, ne);
    if(e <= ns || ne <= s) return;
    if(s <= ns && ne <= e){
        lazy[node] += w;
        propagate(node, ns, ne);
        return;
    }
    int mid = (ns + ne) / 2;
    add(s, e, w, node*2, ns, mid);
    add(s, e, w, node*2+1, mid, ne);
    seg[node] = seg[node*2] + seg[node*2+1];
}

ll sum(int s, int e, int node, int ns, int ne)
{
    propagate(node, ns, ne);
    if(e <= ns || ne <= s) return 0;
    if(s <= ns && ne <= e) return seg[node];
    int mid = (ns + ne) / 2;
    return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(seg, seg+MAX_ST, 0);
    fill(lazy, lazy+MAX_ST, 0);
    cin >> N >> M;
    for(int i = 0, k; i < N; i++){
        cin >> k;
        if(k < 0) root = i;
        else adj[k-1].push_back(i);
    }
    build(root);
    for(int i = 0; i < M; i++){
        int a, b, w; cin >> a >> b;
        --b;
        if(a == 1){
            cin >> w;
            add(L[b], R[b]+1, w, 1, 0, start);
        }
        else{
            cout << sum(num_to_node[b], num_to_node[b]+1, 1, 0, start) << '\n';
        }
    }
    return 0;
}
