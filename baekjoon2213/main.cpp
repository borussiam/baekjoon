#include <bits/stdc++.h>
using namespace std;
vector<int> g[10001];
int n,w[10001],visit[10001],dp[10001][2];
bool in[10001];
int f(int v,int select)
{
    int &ret=dp[v][select];
    if(ret!=-1) return ret;
    ret=0; visit[v]=1;
    if(select){
        for(int i=0;i<g[v].size();i++){
            if(!visit[g[v][i]]){
                ret+=f(g[v][i],0);
            }
        }
        ret+=w[v];
    }
    else{
        for(int i=0;i<g[v].size();i++){
            if(!visit[g[v][i]]){
                ret+=max(f(g[v][i],0),f(g[v][i],1));
            }
        }
    }
    visit[v]=0;
    return ret;
}
void element(int v,int par)
{
    visit[v]=1;
    if(!in[par]&&dp[v][0]<dp[v][1])
        in[v]=true;
    for(int i=0;i<g[v].size();i++){
        if(!visit[g[v][i]])
            element(g[v][i],v);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<10001;i++)
        dp[i][0]=dp[i][1]=-1;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> w[i];
    for(int i=1,a,b;i<n;i++){
        cin >> a >> b;
        g[a].push_back(b); g[b].push_back(a);
    }
    cout << max(f(1,0),f(1,1)) << '\n';
    element(1,0);
    for(int i=1;i<=n;i++) if(in[i]) cout << i << ' ';
    cout << '\n';
    return 0;
}
