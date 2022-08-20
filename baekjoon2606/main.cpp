#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 100;

vector<int> g[MAX];
bool visited[MAX];
int ans=0;

int dfs(int n)
{
    visited[n] = true;
    int ret = 0;
    for(int next : g[n]){
        if(!visited[next]){
            ret += dfs(next);
        }
    }
    return ret+1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    for(int i = 0, u, v; i < k; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = dfs(1) - 1;
    cout << ans << '\n';
    return 0;
}
