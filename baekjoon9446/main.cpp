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

ll n, m, dp[10101];
bool vis[10101];
vector<pl> make[10101];
priority_queue<pi, vector<pi>, greater<pi> > pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(dp, dp+10101, -1);
    cin >> n >> m;
    for(ll i = 0; i < n; i++){
        cin >> dp[i];
        pq.push({dp[i], i});
    }
    for(ll i = 0, a, x, y; i < m; i++){
        cin >> a >> x >> y;
        --a; --x; --y;
        make[x].push_back({y, a});
        make[y].push_back({x, a});
    }
    while(!pq.empty()){
        ll curr = pq.top().se; pq.pop();
        if(vis[curr]) continue;
        for(auto next : make[curr]){
            if(vis[next.fi] && dp[next.se] > dp[next.fi] + dp[curr]){
                dp[next.se] = dp[next.fi] + dp[curr];
                pq.push({dp[next.se], next.se});
            }
        }
        vis[curr] = true;
    }
    cout << dp[0] << '\n';
    return 0;
}
