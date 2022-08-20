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

const double e = 1e-6;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; double T; cin >> N >> T;
    double x[N], v[N], mn = 0, mx = 1.1e18;
    bool ans = true;
    for(int i = 0; i < N; i++) cin >> x[i];
    for(int i = 0; i < N; i++) cin >> v[i];
    for(int i = 0; i < N; i++){
        double tmn = x[i]-v[i]*T, tmx = x[i]+v[i]*T;
        // cout << tmn << ' ' << tmx << '\n';
        if(tmn - mx > e || mn - tmx > e){
            ans = false;
            break;
        }
        if(tmn - mn > e) mn = tmn;
        if(mx - tmx > e) mx = tmx;
    }
    cout << ans ? 1 : 0 << '\n';
    return 0;
}