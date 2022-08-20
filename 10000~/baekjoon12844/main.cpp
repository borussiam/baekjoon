#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX_ST = 1<<20;
int N, M, start = MAX_ST / 2, seg[MAX_ST], lazy[MAX_ST];

void propagate(int node, int ns, int ne)
{
    if(lazy[node] != 0){
        if(node < start){
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        else{
            seg[node] ^= lazy[node];;
        }
        lazy[node] = 0;
    }
}

void mod(int s, int e, int k, int node, int ns, int ne)
{
    propagate(node, ns, ne);
    if(e <= ns || ne <= s){
        return;
    }
    if(s <= ns && ne <= e){
        lazy[node] ^= k;
        propagate(node, ns, ne);
        return;
    }
    int mid = (ns + ne) / 2;
    mod(s, e, k, node*2, ns, mid);
    mod(s, e, k, node*2+1, mid, ne);
    seg[node] = seg[node*2] ^ seg[node*2+1];
}

int exor(int s, int e, int node, int ns, int ne)
{
    propagate(node, ns, ne);
    if(e <= ns || ne <= s){
        return 0;
    }
    if(s <= ns && ne <= e){
        return seg[node];
    }
    int mid = (ns + ne) / 2;
    return exor(s, e, node*2, ns, mid) ^ exor(s, e, node*2+1, mid, ne);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(seg, seg+MAX_ST, 0);
    fill(lazy, lazy+MAX_ST, 0);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> seg[start+i];
    }
    for(int i = start-1; i > 0; i--){
        seg[i] = seg[i*2] ^ seg[i*2+1];
    }
    cin >> M;
    for(int i = 0, a, b, c; i < M; i++){
        cin >> a >> b >> c;
        if(a == 1){
            int k; cin >> k;
            mod(b, c+1, k, 1, 0, start);
        }
        else{
            cout << exor(b, c+1, 1, 0, start) << '\n';
        }
    }
    return 0;
}
