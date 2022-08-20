#include <bits/stdc++.h>
using namespace std;
int n,a[501],t[501],indegree[501],dp[501];
vector<int> g[501];
int ti(int n)
{
    int &ret=dp[n];
    if(dp[n]!=0) return ret;
    if(g[n].empty()) return ret=t[n];
    for(int i=0;i<g[n].size();i++){
        if(ret<ti(g[n][i])) ret=ti(g[n][i]);
    }
    ret+=t[n];
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> t[i];
        while(1){
            int a;
            cin >> a;
            if(a==-1) break;
            g[i].push_back(a);
        }
    }
    for(int i=1;i<=n;i++) cout << ti(i) << '\n';
    return 0;
}
