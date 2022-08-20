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

const int MAX = 1005, INF = 1e9;
int N, W, x[MAX], y[MAX], dp[MAX][MAX], ans = INF;
int ch[MAX];
pi pr[MAX][MAX], k;

inline int dist(int i, int j)
{
    if(j == 0) j = W+1;
    return abs(x[j] - x[i]) + abs(y[j] - y[i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(dp[0], dp[MAX-1]+MAX, INF);
    cin >> N >> W;
    x[0] = y[0] = 1; x[W+1] = y[W+1] = N;
    for(int i = 1; i <= W; i++) cin >> x[i] >> y[i];
    dp[1][0] = dist(0, 1); pr[1][0] = {0, 0};
    dp[0][1] = dist(1, 0); pr[0][1] = {0, 0};
    for(int i = 1; i < W; i++){
        for(int j = i+1; j <= W; j++){
            dp[j][i-1] = dp[j-1][i-1] + dist(j-1, j);
            pr[j][i-1] = {j-1, i-1};
            dp[i-1][j] = dp[i-1][j-1] + dist(j-1, j);
            pr[i-1][j] = {i-1, j-1};
        }
        for(int k = 0; k < i; k++){
            if(dp[i+1][i] > dp[k][i] + dist(k, i+1)){
                dp[i+1][i] = dp[k][i] + dist(k, i+1);
                pr[i+1][i] = {k, i};
            }
            if(dp[i][i+1] > dp[i][k] + dist(i+1, k)){
                dp[i][i+1] = dp[i][k] + dist(i+1, k);
                pr[i][i+1] = {i, k};
            }
        }
    }
    // for(int i = 0; i <= W; i++){
    //     for(int j = 0; j <= W; j++){
    //         if(dp[i][j] == INF) printf("0 ");
    //         else printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    for(int i = 0; i < W; i++){
        if(ans > dp[W][i]){
            ans = dp[W][i];
            k = {W, i};
        }
        if(ans > dp[i][W]){
            ans = dp[i][W];
            k = {i, W};
        }
    }
    while(max(k.fi, k.se) != 0){
        if(k.fi > k.se) ch[max(k.fi, k.se)] = 1;
        else ch[max(k.fi, k.se)] = 2;
        k = pr[k.fi][k.se];
    }
    cout << ans << '\n';
    for(int i = 1; i <= W; i++) cout << ch[i] << '\n';
    return 0;
}
