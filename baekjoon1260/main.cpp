#include <bits/stdc++.h>
using namespace std;

int n,mp[1001][1001]={0},visit_d[1001],visit_b[1001];
queue<int> q;

void dfs(int v)
{
    visit_d[v]=1;
    cout << v << ' ';
    for(int i=1;i<=n;i++){
        if(mp[v][i]==1&&!visit_d[i]){
            dfs(i);
        }
    }
}

void bfs(int v)
{
    visit_b[v]=1;
    cout << v << ' ';
    q.push(v);
    while(!q.empty()){
        v=q.front(); q.pop();
        for(int i=1;i<=n;i++){
            if(mp[v][i]==1&&!visit_b[i]){
                visit_b[i]=1;
                q.push(i);
                cout << i << ' ';
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,v;
    cin >> n >> m >> v;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        mp[a][b]=1; mp[b][a]=1;
    }
    dfs(v);
    cout << '\n';
    bfs(v);
    cout << '\n';
    return 0;
}
