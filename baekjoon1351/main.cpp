#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p,q;
map<ll,ll> dp;
ll f(ll a)
{
    map<ll,ll>::iterator iter=dp.find(a);
    if(iter!=dp.end()) return iter->second;
    ll ret=f(a/p)+f(a/q);
    dp.insert({a,ret});
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    dp.insert({0,1});
    cin >> n >> p >> q;
    cout << f(n) << '\n';
    return 0;
}
