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

const int INF = 1e8;
int n, k, dp[50050][4], a[50050], b[50050];

int f(int start, int left)
{
    if(left == 0) return 0;
    if(start >= n-k+1) return -INF;
    int &ret = dp[start][left];
    if(ret != -1) return ret;
    ret = max(f(start+1, left), f(start+k, left-1) + b[start]);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> k;
    for(int i = 0; i < k; i++) b[0] += a[i];
    for(int i = 1; i < n-k+1; i++)
        b[i] = b[i-1] - a[i-1] + a[i+k-1];
    cout << f(0, 3) << '\n';
    return 0;
}
