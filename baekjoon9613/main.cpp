#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll a[n], ans = 0;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                ans += gcd(a[i], a[j]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
