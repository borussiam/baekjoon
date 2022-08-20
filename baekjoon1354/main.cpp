#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p,q,x,y;
map<ll,ll> dp;
ll f(ll a)
{
    if(a<=0) return 1;
    map<ll,ll>::iterator iter=dp.find(a);
    if(iter!=dp.end()) return iter->second;
    ll ret=f(a/p-x)+f(a/q-y);
    dp.insert({a,ret});
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> p >> q >> x >> y;
    cout << f(n) << '\n';
    return 0;
}
