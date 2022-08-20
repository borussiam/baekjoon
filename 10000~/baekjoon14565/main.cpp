#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll inv_add(ll a, ll mod)
{
    return (mod-a%mod)%mod;
}

ll ext_gcd(ll a, ll b, ll &x, ll &y)
{
    ll g = a; x = 1, y = 0;
    if(b) g = ext_gcd(b, a%b, y, x), y -= (a/b) * x;
    return g;
}

ll inv_mul(ll a, ll mod)
{
    ll g, x, y;
    g = ext_gcd(a, mod, x, y);
    if(g>1) return -1;
    x=((x%mod)+mod)%mod; return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,a; cin >> n >> a;
    cout << inv_add(a,n) << ' ' << inv_mul(a,n) << '\n';
    return 0;
}
