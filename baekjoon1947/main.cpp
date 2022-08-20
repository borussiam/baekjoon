#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000000;
ll dp[1000100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[0]=0; dp[1]=0; dp[2]=1;
    for(int i = 3; i <= 1000000; i++){
        dp[i] = ((i - 1) * (dp[i-1] + dp[i-2]))%MOD;
    }
    int n; cin >> n; cout << dp[n] << '\n';
    return 0;
}
