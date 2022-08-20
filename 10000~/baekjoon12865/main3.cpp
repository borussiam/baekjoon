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
    int n, k; cin >> n >> k;
    int dp[k+1];
    fill(dp, dp+k+1, 0);
    for(int i = 0, w, v; i < n; i++){
        cin >> w >> v;
        for(int j = k; j >= w; j--){
            if(dp[j] < dp[j-w] + v){
                dp[j] = dp[j-w] + v;
            }
        }
    }
    cout << dp[k] << '\n';
    return 0;
}
