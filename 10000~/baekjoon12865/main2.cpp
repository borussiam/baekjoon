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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K; cin >> N >> K;
    int dp[K+1], w, v;
    fill(dp, dp+K+1, 0);
    for(int i = 0; i < N; i++){
        cin >> w >> v;
        for(int j = K; j >= w; j--){
            if(dp[j-w] + v > dp[j]){
                dp[j] = dp[j-w] + v;
            }
        }
    }
    cout << dp[K] << '\n';
    return 0;
}
