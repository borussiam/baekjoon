#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

vector<pii> g[10001];
int n, visited[10001], furthest, max_dst;

void dfs(int v,int mx)
{
    if(mx > max_dst){
        max_dst = mx;
        furthest = v;
    }
    visited[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        if(!visited[g[v][i].first]){
            dfs(g[v][i].first, mx+g[v][i].second);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    dfs(1, 0);
    memset(visited, 0, sizeof(visited)); max_dst=0;
    dfs(furthest, 0);
    cout << max_dst << '\n';
    return 0;
}
