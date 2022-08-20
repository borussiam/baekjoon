#include <bits/stdc++.h>
using namespace std;
int n,m,visit[1001];
vector<int> g[1001];
void dfs(int curr)
{
    visit[curr]=1;
    for(int nxt=0;nxt<g[curr].size();nxt++){
        if(!visit[g[curr][nxt]])
            dfs(g[curr][nxt]);
    }
}
int dfs_all()
{
    int comp=0;
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            dfs(i);
            comp++;
        }
    }
    return comp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b); g[b].push_back(a);
    }
    cout << dfs_all() << '\n';
    return 0;
}
