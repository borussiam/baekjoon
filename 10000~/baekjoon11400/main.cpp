#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
#define fi first
#define se second
#define pb push_back

const int MAX = 1e5+5;
int n, m, num[MAX], number = 0;
vector<int> adj[MAX];
vector<pi> edge, bridge;

int dfs(int curr, int par)
{
    num[curr] = ++number;
    int ret = num[curr];
    for(int &next : adj[curr]){
        if(next == par) continue;
        if(num[next]){
            ret = min(ret, num[next]);
            continue;
        }
        int prev = dfs(next, curr);
        if(prev > num[curr]){
            bridge.pb({min(curr, next), max(curr, next)});
        }
        ret = min(ret, prev);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].pb(v);
        adj[v].pb(u);
        edge.pb({min(u, v), max(u, v)});
    }
    for(int i = 0; i < n; i++){
        if(!num[i]) dfs(i, 0);
    }
    sort(bridge.begin(), bridge.end());
    cout << bridge.size() << '\n';
    for(int i = 0; i < bridge.size(); i++){
        cout << bridge[i].fi+1 << ' ' << bridge[i].se+1 << '\n';
    }
    return 0;
}
