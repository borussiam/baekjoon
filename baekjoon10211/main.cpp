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
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        int a[N], dp[N], ans;
        for(int i = 0; i < N; i++) cin >> a[i];
        dp[0] = ans = a[0];
        for(int i = 1; i < N; i++){
            dp[i] = max(0, dp[i-1]) + a[i];
            if(ans < dp[i]) ans = dp[i];
        }
        cout << ans << '\n';
    }
    return 0;
}
