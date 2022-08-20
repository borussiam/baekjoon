#include <bits/stdc++.h>
using namespace std;
int n,x[3000],y[3000],r[3000],visit[3000];
vector<int> v[3000];
void dfs(int n)
{
    visit[n]=1;
    for(int i=0;i<v[n].size();i++){
        if(!visit[v[n][i]])
            dfs(v[n][i]);
    }
}
int dfs_all()
{
    int ret=0;
    for(int i=0;i<n;i++){
        if(!visit[i]){
            dfs(i);
            ret++;
        }
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        memset(visit,0,sizeof(visit));
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> x[i] >> y[i] >> r[i];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=(r[i]+r[j])*(r[i]+r[j])){
                    v[i].push_back(j); v[j].push_back(i);
                }
            }
        }
        cout << dfs_all() << '\n';
        for(int i=0;i<n;i++) if(!v[i].empty()) v[i].clear();
    }
    return 0;
}
