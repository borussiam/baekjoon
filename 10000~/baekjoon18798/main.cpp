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

const int MAX = 2.5e5, MAX_ST = 1<<19, start = MAX_ST/2;
int N, M, K, q, l, r, x, seg[MAX_ST][2];

void mod(int s, int e, int x, int node, int ns, int ne)
{
    if(e <= ns || ne <= s) return;
    if(s <= ns && ne <= e){
        if((seg[node][0] | x) == seg[node][0]) return;
    }
    if(node >= start){
        seg[node][0] |= x;
        if(seg[node][0] == K) seg[node][1] = 1;
        else seg[node][1] = 0;
        return;
    }
    int mid = (ns + ne) / 2;
    mod(s, e, x, node*2, ns, mid);
    mod(s, e, x, node*2+1, mid, ne);
    seg[node][0] = seg[node*2][0] & seg[node*2+1][0];
    seg[node][1] = seg[node*2][1] + seg[node*2+1][1];
}

int sum(int s, int e, int node, int ns, int ne)
{
    if(e <= ns || ne <= s) return 0;
    if(s <= ns && ne <= e) return seg[node][1];
    int mid = (ns + ne) / 2;
    return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> seg[start+i][0];
        if(seg[start+i][0] == K) seg[start+i][1] = 1;
    }
    for(int i = start-1; i > 0; i--){
        seg[i][0] = seg[i*2][0] & seg[i*2+1][0];
        seg[i][1] = seg[i*2][1] + seg[i*2+1][1];
    }
    cin >> M;
    while(M--){
        cin >> q >> l >> r;
        if(q == 1){
            cin >> x;
            mod(l-1, r, x, 1, 0, start);
        }
        else{
            cout << sum(l-1, r, 1, 0, start) << '\n';
        }
    }
    return 0;
}
