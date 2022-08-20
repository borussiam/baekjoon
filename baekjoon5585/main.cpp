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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    n = 1000 - n;
    int ans = 0;
    if(n >= 500){
        ans += n/500;
        n -= 500*(n/500);
    }
    if(n >= 100){
        ans += n/100;
        n -= 100*(n/100);
    }
    if(n >= 50){
        ans += n/50;
        n -= 50*(n/50);
    }
    if(n >= 10){
        ans += n/10;
        n -= 10*(n/10);
    }
    if(n >= 5){
        ans += n/5;
        n -= 5*(n/5);
    }
    ans += n;
    cout << ans << '\n';
    return 0;
}
