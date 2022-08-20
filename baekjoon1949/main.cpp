#include <bits/stdc++.h>
using namespace std;
vector<int> g[10001];
int dp[10001][2],po[10001],visit[10001];
int f(int v,int isGood)
{
    visit[v]=1;
    int &ret=dp[v][isGood];
    if(ret!=-1) return ret;
    ret=0;
    if(isGood){
        for(int i=0;i<g[v].size();i++){
            if(!visit[g[v][i]])
                ret+=f(g[v][i],0);
        }
        ret+=po[v];
    }
    else{
        for(int i=0;i<g[v].size();i++){
            if(!visit[g[v][i]])
                ret+=max(f(g[v][i],0),f(g[v][i],1));
        }
    }
    visit[v]=0;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<10001;i++)
        dp[i][0]=dp[i][1]=-1;
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> po[i];
    for(int i=1,a,b;i<n;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << max(f(1,0),f(1,1)) << '\n';
    return 0;
}
