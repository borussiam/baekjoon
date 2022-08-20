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

const int MAX = 1e5;
int N, K, ps[MAX+1];
pi x[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> x[i].se >> x[i].fi;
    sort(x, x+N);
    for(int i = 0; i < N; i++) ps[i+1] = ps[i] + x[i].se;
    ll ans = 0;
    for(int i = 0; i <= 1000000; i++){
        int l = lower_bound(x, x+N, make_pair(i-K, 0)) - x;
        int r = upper_bound(x, x+N, make_pair(i+K, 100000)) - x;
        if(ans < ps[r] - ps[l]) ans = ps[r] - ps[l];
    }
    cout << ans << '\n';
    return 0;
}
