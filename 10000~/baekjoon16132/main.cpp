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

ll dp[2200][55];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    int sum = N*(N+1)/2;
    if(sum%2){
        cout << "0\n";
        return 0;
    }
    dp[0][0] = 1;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= sum/2; j++){
            dp[j+i+1][i+1] += dp[j][i];
            dp[j][i+1] += dp[j][i];
        }
    }
    cout << dp[sum/2][N]/2 << '\n';
    return 0;
}
