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

int N, a[2][404], x[2], dp[404][404][404];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0; i < 2; i++){
        for(int j = 0, k; j < N; j++){
            cin >> k;
            if(k != 0){
                a[i][++x[i]] = k;
            }
        }
    }
    // printf("%d %d\n", x[0], x[1]);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= min(i, x[0]); j++){
            for(int k = 1; k <= min(i, x[1]); k++){
                dp[i][j][k] = dp[i-1][j-1][k-1] + a[0][j] * a[1][k];
                if(i != j) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1]);
                if(i != k) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k]);
            }
        }
    }
    cout << dp[N][x[0]][x[1]] << '\n';
    return 0;
}
