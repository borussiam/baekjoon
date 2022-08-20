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

int n, K, a[505], dp[505][505], lis[505][505], d[505];

int f(int start, int left)
{
    if(left == 0) return lis[start][n-1];
    int &ret = dp[start][left];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = start; i < n; i++)
        ret = max(ret, f(i+1, left-1)+lis[start][i]);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    cin >> n >> K;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        fill(d, d+505, 0);
        int len = 0;
        for(int j = i; j < n; j++){
            if(a[j] >= d[len]) d[++len] = a[j];
            else{
                int idx = lower_bound(d, d+len, a[j]) - d;
                d[idx] = a[j];
            }
            lis[i][j] = len;
        }
    }
    cout << f(0, K) << '\n';
    return 0;
}
