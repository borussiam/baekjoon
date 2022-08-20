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

const int MAX = 1e6+1, INF = 1e7;
int dp[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(dp, dp+MAX, INF);
    dp[1] = 0; dp[2] = 1; dp[3] = 1;
    for(int i = 4; i < MAX; i++){
        if(i%2==0){
            dp[i] = min(dp[i], dp[i/2]+1);
        }
        if(i%3==0){
            dp[i] = min(dp[i], dp[i/3]+1);
        }
        dp[i] = min(dp[i], dp[i-1]+1);
    }
    int n; cin >> n;
    cout << dp[n] << '\n';
    return 0;
}
