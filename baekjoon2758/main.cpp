#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, dp[11][2001];

ll lotto(int decided, int last)
{
    if(decided > last) return 0;
    if(decided == 1) return last;
    ll &ret = dp[decided][last];
    if(ret != -1) return ret;
    ret = lotto(decided, last-1) + lotto(decided-1, last/2);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        cin >> n >> m;
        cout << lotto(n, m) << '\n';
    }
    return 0;
}
