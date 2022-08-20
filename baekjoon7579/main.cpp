#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100;
int m[MAX+1], c[MAX+1], sum_c[MAX+1], dp[MAX+1][MAX*MAX+1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> m[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> c[i];
        sum_c[i] = c[i] + sum_c[i-1];
    }
    fill(dp[0], dp[0]+MAX*MAX+1, 0);
    for(int i = 1; i <= N; i++){
        fill(dp[i], dp[i]+MAX*MAX+1, -1);
    }
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < c[i]; j++){
            dp[i][j] = dp[i-1][j];
        }
        for(int j = c[i]; j <= sum_c[i]; j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-c[i]]+m[i]);
        }
    }
    int ans = 0;
    while(dp[N][ans] < M){
        ++ans;
    }
    cout << ans << '\n';
    return 0;
}
