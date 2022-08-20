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

ll N, max_dist, furthest;
bool vis[101010];
vector<pl> adj[101010];

void dfs(ll curr, ll dist)
{
    vis[curr] = true;
    if(dist > max_dist){
        max_dist = dist;
        furthest = curr;
    }
    for(auto next : adj[curr]){
        if(!vis[next.fi]){
            dfs(next.fi, dist+next.se);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(ll i = 0, u, v, w; i < N-1; i++){
        cin >> u >> v >> w;
        --u; --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    ll longest[2], temp[2];
    
    dfs(0, 0);
    longest[0] = furthest;
    
    max_dist = 0; fill(vis, vis+101010, false);
    dfs(longest[0], 0);
    longest[1] = furthest;
    
    max_dist = 0; fill(vis, vis+101010, false);
    vis[longest[0]] = true;
    dfs(longest[1], 0);
    temp[0] = max_dist;

    max_dist = 0; fill(vis, vis+101010, false);
    vis[longest[1]] = true;
    dfs(longest[0], 0);
    temp[1] = max_dist;

    cout << max(temp[0], temp[1]) << '\n';
    return 0;
}
