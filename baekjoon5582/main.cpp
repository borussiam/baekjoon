#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    int dp[n+1][m+1], ans = 0;
    for(int i = 0; i < n+1; i++){
        fill(dp[i], dp[i]+m+1, 0);
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            if(ans < dp[i][j]){
                ans = dp[i][j];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
