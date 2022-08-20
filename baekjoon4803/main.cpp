#include <bits/stdc++.h>
using namespace std;
int n,m,visit[501],edge,node;
vector<int> g[501];
void dfs(int curr)
{
    node++;
    visit[curr]=1;
    for(int nxt=0;nxt<g[curr].size();nxt++){
        edge++;
        if(!visit[g[curr][nxt]])
            dfs(g[curr][nxt]);
    }
}
int dfs_all()
{
    memset(visit,0,sizeof(visit));
    int tree=0;
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            edge=0; node=0;
            dfs(i);
            if(edge==2*(node-1)) tree++;
        }
    }
    return tree;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int p=1;
    while(1){
        for(int i=1;i<=n;i++){
            if(!g[i].empty()) g[i].clear();
        }
        cin >> n >> m;
        if(!n&&!m) return 0;
        for(int i=0;i<m;i++){
            int a,b; cin >> a >> b;
            g[a].push_back(b); g[b].push_back(a);
        }
        int k=dfs_all();
        cout << "Case " << p << ": ";
        if(k>1) cout << "A forest of " << k << " trees.\n";
        else if(k==1) cout << "There is one tree.\n";
        else cout << "No trees.\n";
        p++;
    }
}
