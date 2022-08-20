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

const int MAX = 500, INF = 1e9;
int a[MAX], dp[MAX][MAX], preSum[MAX+1];

int merge(int s, int e)
{
    int &ret = dp[s][e];
    if(s >= e) return ret = 0;
    if(ret != INF) return ret;
    if(e == s+1) return ret = a[s]+a[e];
    for(int i = s; i < e; i++){
        ret = min(ret, merge(s, i)+merge(i+1, e));
    }
    ret += preSum[e+1] - preSum[s];
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        fill(a, a+MAX, 0);
        for(int i = 0; i < MAX; i++){
            fill(dp[i], dp[i]+MAX, INF);
            dp[i][i] = 0;
        }
        int k; cin >> k;
        for(int i = 0; i < k; i++){
            cin >> a[i];
            preSum[i+1] = a[i] + preSum[i];
        }
        cout << merge(0, k-1) << '\n';
    }
    return 0;
}
