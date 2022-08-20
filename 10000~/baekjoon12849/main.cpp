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

const ll MOD = 1e9+7;
vector<int> adj[8];
ll dp[8][100005];
int D;

ll move(int curr, int time)
{
    if(time == D){
        if(curr == 0) return 1;
        return 0;
    }
    ll &ret = dp[curr][time];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < adj[curr].size(); i++){
        ret += move(adj[curr][i], time+1);
        ret %= MOD;
    }
    return ret % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    adj[0].pb(1); adj[0].pb(2);
    adj[1].pb(0); adj[1].pb(2); adj[1].pb(3);
    adj[2].pb(0); adj[2].pb(1); adj[2].pb(3); adj[2].pb(4);
    adj[3].pb(1); adj[3].pb(2); adj[3].pb(4); adj[3].pb(5);
    adj[4].pb(2); adj[4].pb(3); adj[4].pb(5); adj[4].pb(7);
    adj[5].pb(3); adj[5].pb(4); adj[5].pb(6);
    adj[6].pb(5); adj[6].pb(7);
    adj[7].pb(4); adj[7].pb(6);

    cin >> D;
    cout << move(0, 0) << '\n';
    return 0;
}
