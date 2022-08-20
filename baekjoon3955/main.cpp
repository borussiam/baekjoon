#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ext_gcd(ll a, ll b, ll &x, ll &y)
{
    ll g = a; x = 1, y = 0;
    if(b) g = ext_gcd(b, a%b, y, x), y -= (a/b) * x;
    return g;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        ll K, C, X, Y; cin >> K >> C;
        ll gcd = ext_gcd(K, C, X, Y);
        if(gcd>1){
            cout << "IMPOSSIBLE\n";
            continue;
        }
//        cout << "before: " << X << ' ' << Y << '\n';
        if(0<=Y && Y<=1e9 && X<0){
            cout << Y << '\n';
            continue;
        }
        ll low = (K-Y-1)/K, high = (X+C)/C;
        if(Y + max(low,high)*K > 1e9){
            cout << "IMPOSSIBLE\n";
            continue;
        }
        else{
            cout << Y+max(low,high)*K << '\n';
        }
    }
    return 0;
}
