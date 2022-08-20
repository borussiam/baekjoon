#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

double dp[1000100], sum = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 1; i <= 6; i++){
        dp[i] += (7-i)/6.0;
        for(int j = 1; j < i; j++){
            dp[i] += (dp[j] + 1)/6.0;
        }
        sum += dp[i];
    }
    for(int i = 7; i < 1000001; i++){
        dp[i] = 1 + sum / 6;
        sum += dp[i] - dp[i - 6];
    }
    int n; cin >> n;
    cout << setprecision(18) << dp[n] << '\n';
    return 0;
}
