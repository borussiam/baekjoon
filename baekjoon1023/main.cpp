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

const ll MAX = 52;
ll N, K, dp[MAX][130], cnt = 60, sub = 0;
string ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(dp[0], dp[0]+130, 1); dp[0][60] = 0;
    fill(dp[1], dp[1]+130, 2); dp[1][61] = 1;
    for(int i = 2; i < MAX; i++){
        for(int j = 1; j < 60; j++){
            dp[i][j] = (1ll << i);
            // printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
        }
        for(int j = 60; j <= 120; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            // printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
        }
    }
    cin >> N >> K;
    if(K+1 > dp[N][60]){
        cout << "-1\n";
        return 0;
    }
    bool pos = true;
    for(int i = N; i > 0; i--){
        ll cmp = dp[i-1][cnt+1];
        if(!pos) cmp = 1ll << (i-1);
        if(sub + cmp > K){
            ans += "(";
            ++cnt;
        }
        else{
            sub += cmp;
            ans += ")";
            --cnt;
        }
        if(cnt < 60) pos = false;
    }
    cout << ans << '\n';
    return 0;
}
