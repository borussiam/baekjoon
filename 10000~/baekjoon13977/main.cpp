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

ll power(ll a, ll b, ll mod)
{
    if(a == 0) return 0;
    if(a == 1) return 1;
    if(b == 0) return 1;
    if(b == 1) return a % mod;
    ll ret = 1;
    while(b){
        if(b % 2) ret = (ret * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ret;
}

const ll MAX = 4e6+4, MOD = 1e9+7;
ll M, N, K, f[MAX], finv[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    f[0] = 1;
    for(int i = 1; i < MAX; i++){
        f[i] = (f[i-1] * i) % MOD;
    }
    finv[MAX-1] = power(f[MAX-1], MOD-2, MOD);
    for(int i = MAX-2; i >= 0; i--) finv[i] = (finv[i+1] * (i+1)) % MOD;
    cin >> M;
    while(M--){
        cin >> N >> K;
        cout << (((f[N] * finv[K]) % MOD) * finv[N-K]) % MOD << '\n';
    }
    return 0;
}
