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
int N, M;
pi seg[MAX_ST];

pi min(pi &a, pi &b)
{
    if(a.fi < b.fi) return a;
    else if(a.fi > b.fi) return b;
    else if(a.se < b.se) return a;
    else return b;
}

void upd(int loc, int v)
{
    loc += start;
    seg[loc].fi = v;
    while(loc > 1){
        loc /= 2;
        seg[loc] = min(seg[loc*2], seg[loc*2+1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i < MAX_ST; i++){
        seg[i].fi = 1e9+1;
    }
    cin >> N;
    for(int i = 0, k; i < N; i++){
        cin >> k;
        seg[start+i] = {k, i};
    }
    for(int i = start-1; i > 0; i--){
        seg[i] = min(seg[i*2], seg[i*2+1]);
        // cout << seg[i].fi << ' ' << seg[i].se << '\n';
    }
    cin >> M;
    for(int i = 0, q, a, b; i < M; i++){
        cin >> q;
        if(q == 1){
            cin >> a >> b;
            upd(a-1, b);
        }
        else cout << seg[1].se+1 << '\n';
    }
    return 0;
}
