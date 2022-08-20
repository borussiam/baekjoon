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
    int p[n+1], dp[n+1];
    for(int i = 1; i <= n; i++) cin >> p[i];
    dp[0] = 0; dp[1] = p[1]; dp[2] = p[1]+p[2];
    for(int i = 2; i <= n; i++){
        dp[i] = p[i] + max(dp[i-2], dp[i-3]+p[i-1]);
    }
    cout << dp[n] << '\n';
    return 0;
}
