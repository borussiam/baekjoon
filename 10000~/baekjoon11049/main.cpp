#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    int M[N][2];
    ll dp[N][N];
    for(int i = 0;i < N; i++){
        fill(dp[i], dp[i]+N, 0);
    }
    for(int i = 0; i < N; i++){
        cin >> M[i][0] >> M[i][1];
    }
    for(int i = 0; i < N-1; i++){
        dp[i][i+1] = M[i][0] * M[i][1] * M[i+1][1];
        dp[i][i] = 0;
        if(i == N-2){
            dp[i+1][i+1] = 0;
        }
    }
    for(int len = 2; len < N; len++){
        for(int i = 0; i < N-len; i++){
            int j = i+len;
            dp[i][j] = INF;
            for(int k = 0; k < len; k++){
                dp[i][j] = min(dp[i][j], dp[i][i+k] + M[i][0]*M[i+k+1][0]*M[j][1] + dp[i+k+1][j]);
            }
            // dp[i][i+len] = min(dp[i][i+interval] + M[i][0]*M[i+interval+1][0]*M[i+interval+1][1], M[i][0]*M[i][1]*M[i+interval+1][1] + dp[i+1][i+interval+1]);
        }
    }
    // for(int i = 0; i < N-1; i++){
    //     cout << dp[i][i+1] << ' ';
    // }
    // cout << '\n';
    // for(int interval = 1; interval < N-1; interval++){
    //     for(int i = 0; i < N-interval-1; i++){
    //         cout << dp[i][i+interval+1] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "\n\n";
    cout << dp[0][N-1] << '\n';
    return 0;
}
