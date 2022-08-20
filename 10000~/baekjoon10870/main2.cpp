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

int dp[22];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[0] = 0; dp[1] = 1;
    for(int i = 2; i < 22; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    int n; cin >> n;
    cout << dp[n];
    return 0;
}
