#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, a[20], b[20], dp[1050];

int f(int left)
{
    if(left <= 0) return 0;
    int &ret = dp[left];
    if(ret != -1) return ret;
    ret = 1e9;
    for(int i = 0; i < n; i++){
        ret = min(f(left - b[i]) + a[i], ret);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    int c; cin >> c >> n;
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    int ans = f(c);
    cout << ans << '\n';
    return 0;
}
