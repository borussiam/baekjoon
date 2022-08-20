#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, b; cin >> n >> b;
    pair<ll, ll> price[n];
    ll p[n], s[n], sum = 0;
    bool inc = false;
    for(int i = 0; i < n; i++){
        cin >> p[i] >> s[i];
    }
    for(int i = 0; i < n; i++){
        price[i].first = p[i] + s[i];
        price[i].second = p[i];
    }
    sort(price, price + n);
    int ans = 0;
    while(sum + price[ans].first <= b){
        sum += price[ans++].first;
    }
    // cout << sum << ' ' << ans << '\n';
    for(int i = 0; i < ans; i++){
        if((price[i].second+1)/2 + b - sum >= price[ans].first){
            ++ans;
            cout << ans << '\n';
            return 0;
        }
    }
    for(int i = ans; i < n; i++){
        if(price[i].first - (price[i].second+1)/2 <= b - sum){
            ++ans;
            cout << ans << '\n';
            return 0;
        }
    }
    cout << ans << '\n';
    return 0;
}
