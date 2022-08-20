#include <bits/stdc++.h>
using namespace std;

int n,dp[1000005][2];
bool visit[1000005];
vector<int> g[1000005];

int f(int v,int early)
{
    visit[v]=true;
    int &ret=dp[v][early];
    if(ret!=-1) return ret;
    ret=0;
    if(early){
        for(int i=0;i<g[v].size();i++){
            if(!visit[g[v][i]]){
                ret+=min(f(g[v][i],0),f(g[v][i],1));
            }
        }
        ret+=1;
    }
    else{
        for(int i=0;i<g[v].size();i++){
            if(!visit[g[v][i]]){
                ret+=f(g[v][i],1);
            }
        }
    }
    visit[v]=false;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<1000005;i++)
        dp[i][0]=dp[i][1]=-1;
    cin >> n;
    for(int i=1,u,v;i<n;i++){
        cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    cout << min(f(1,0),f(1,1)) << '\n';
    return 0;
}
