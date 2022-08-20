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

const int MAX = 500;
const ll INF = 1e18;
int K, S[MAX], sum[MAX];
ll dp[MAX][MAX];

ll f(int s, int e)
{
    ll &ret = dp[s][e];
    if(ret != -1) return ret;
    if(s == e-1) return 0;
    if(s == e-2) return ret = S[s]+S[e-1];
    ret = INF;
    for(int i = s+1; i < e; i++){
        ret = min(ret, f(s, i) + f(i, e));
    }
    if(s == 0){
        ret += sum[e-1];
    }
    else{
        ret += sum[e-1]-sum[s-1];
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        fill(S, S+MAX, 0);
        fill(sum, sum+MAX, 0);
        for(int i = 0; i < MAX; i++) fill(dp[i], dp[i]+MAX, -1);
        cin >> K;
        cin >> S[0];
        sum[0] = S[0];
        for(int i = 1; i < K; i++){
            cin >> S[i];
            sum[i] = sum[i-1] + S[i];
        }
        cout << f(0, K) << '\n';
    }
    return 0;
}
