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

const int MAX = 1e5+5;
int n, m, num[MAX], number = 0, ans = 0;
bool artic[MAX];
vector<int> adj[MAX];

int dfs(int curr, bool root){
    num[curr] = ++number;
    int ret = num[curr], child = 0;
    for(int &next : adj[curr]){
        if(num[next]){
            ret = min(ret, num[next]);
            continue;
        }
        ++child;
        int prev = dfs(next, false);
        if(!root && prev >= num[curr]){
            artic[curr] = true;
        }
        ret = min(ret, prev);
    }
    if(root && child > 1) artic[curr] = true;
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
    }
    for(int i = 0; i < n; i++){
        if(!num[i]) dfs(i, true);
    }
    for(int i = 0; i < n; i++) ans += artic[i];
    cout << ans << '\n';
    for(int i = 0; i < n; i++){
        if(artic[i]) cout << i+1 << ' ';
    }
    return 0;
}
