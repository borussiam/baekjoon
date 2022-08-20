#include <bits/stdc++.h>
using namespace std;
int n,visit[100001],parent[100001];
vector<int> g[100001];
void dfs(int k)
{
    visit[k]=1;
    for(int i=0;i<g[k].size();i++){
        if(!visit[g[k][i]]){
            dfs(g[k][i]);
            parent[g[k][i]]=k;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b); g[b].push_back(a);
    }
    dfs(1);
    for(int i=2;i<=n;i++)
        cout << parent[i] << '\n';
    return 0;
}
