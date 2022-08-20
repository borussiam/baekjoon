#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
bool b[31];
ll dp[32];

ll get_dp(int idx)
{
    ll &ret = dp[idx];
    if(ret != -1) return ret;
    if(idx == 0) return ret = 1;
    return ret = 2*get_dp(idx-1) + 1;
}

ll f(int idx)
{
    b[idx] ^= 1;
    if(idx == 0) return 1;
    bool chk = false;
    for(int i = idx-1; i >= 0; i--) chk |= b[i];
    if(!chk) return dp[idx];
    ll ret = 0;
    if(!b[idx-1]) ret += f(idx-1);
    for(int i = idx-2; i >= 0; i--){
        if(b[i]) ret += f(i);
    }
    ret += 1;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    get_dp(31);
    int T; cin >> T;
    while(T--){
        string B; cin >> B;
        int leading_zeros = 0;
        while(B[leading_zeros] == '0') ++leading_zeros;
        B = B.substr(leading_zeros);
        n = B.size();
        for(int i = 0; i < n; i++) b[i] = B[n-i-1] - '0';
        ll ans = 0;
        ans += f(n-1);
        if(b[n-2]) ans += dp[n-2];
        cout << ans << '\n';
    }
    return 0;
}
