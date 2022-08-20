#include <bits/stdc++.h>
using namespace std;
int n,m,indegree[1005],visit[1005],check[1005];
set<int> g[1005];
stack<int> ans;
int dfs(int n)
{
    int ret=0;
    visit[n]=1; check[n]=1;
    for(int i=0;i<g[n].size();i++){
        set<int>::iterator iter=g[n].begin();
        for(int j=0;j<i;j++) iter++;
        if(check[*iter]) return -1;
        if(!visit[*iter])
            ret+=dfs(*iter);
    }
    ans.push(n);
    check[n]=0;
    return ret;
}
void dfs_all()
{
    bool flag=false;
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            if(dfs(i)<0){
                flag=true;
                break;
            }
        }
    }
    if(flag) cout << "0\n";
    else{
        for(int i=0;i<n;i++){
            cout << ans.top() << '\n';
            ans.pop();
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int k; cin >> k;
        int a[2];
        if(k==0) continue;
        cin >> a[0];
        for(int j=1;j<k;j++){
            cin >> a[1];
            g[a[0]].insert(a[1]);
            indegree[a[1]]++;
            a[0]=a[1];
        }
    }
    dfs_all();
    return 0;
}
