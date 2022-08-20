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

const ll MOD = 1e9+9;
ll dp[100050][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[1][0] = dp[2][1] = dp[3][0] = dp[3][1] = dp[3][2] = 1;
    for(int i = 4; i < 100050; i++){
        dp[i][0] = (dp[i-1][1] + dp[i-1][2])%MOD;
        dp[i][1] = (dp[i-2][0] + dp[i-2][2])%MOD;
        dp[i][2] = (dp[i-3][0] + dp[i-3][1])%MOD;
    }
    int T, n; cin >> T;
    while(T--){
        cin >> n;
        cout << (dp[n][0] + dp[n][1] + dp[n][2])%MOD << '\n';
    }
    return 0;
}
