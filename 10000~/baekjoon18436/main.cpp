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

const int MAX = 1e5, MAX_ST = 1<<19, start = MAX_ST / 2;
int N, M, seg[MAX_ST];

void upd(int loc, int x)
{
    loc += start;
    seg[loc] = x;
    while(loc > 1){
        loc /= 2;
        seg[loc] = seg[loc*2] + seg[loc*2+1];
    }
}

int odd(int s, int e, int node = 1, int ns = 0, int ne = start)
{
    if(e <= ns || ne <= s) return 0;
    if(s <= ns && ne <= e) return seg[node];
    int mid = (ns + ne) / 2;
    return odd(s, e, node*2, ns, mid) + odd(s, e, node*2+1, mid, ne);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0, k; i < N; i++){
        cin >> k;
        seg[start+i] = k%2;
    }
    for(int i = start-1; i > 0; i--) seg[i] = seg[i*2] + seg[i*2+1];
    cin >> M;
    for(int i = 0, q, a, b; i < M; i++){
        cin >> q >> a >> b;
        if(q == 1) upd(a-1, b%2);
        else if(q == 2) cout << b-a+1-odd(a-1, b) << '\n';
        else cout << odd(a-1, b) << '\n';
    }
    return 0;
}
