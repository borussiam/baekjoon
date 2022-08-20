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

const ll MAX = 1e6+5, INF = 8e18;
ll N, dd = INF;
pl p[MAX];

inline ll dist(pi &a, pi &b)
{
    return (b.fi - a.fi) * (b.fi - a.fi) + (b.se - a.se) * (b.se - a.se);
}

void dnc(vector<pi> &P, int n)
{
    if(n == 1) return;
    if(n == 2){
        dd = min(dd, dist(P[0], P[1]));
        if(P[0].se > P[1].se) swap(P[0], P[1]);
        return;
    }
    int m = P.size() / 2, ldx = 0, rdx = m;
    // dnc(0, m);
    // dnc(m, r);
    vector<int> strip;
    while(ldx < m && rdx < r){
        if()
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> p[i].fi >> p[i].se;
    }
    sort(p, p+N);
    return 0;
}
