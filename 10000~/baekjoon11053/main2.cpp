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

const int INF = 1e5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    int A[N], dp[N+1];
    fill(dp, dp+N, INF);
    for(int i = 0; i < N; i++) cin >> A[i];
    int len = 1;
    for(int i = 0; i < N; i++){
        int idx = lower_bound(dp, dp+len, A[i]) - dp;
        dp[idx] = A[i];
        if(idx == len) ++len;
    }
    cout << len << '\n';
    return 0;
}
