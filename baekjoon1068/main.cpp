#include <bits/stdc++.h>
using namespace std;
int n,k,ans,root,parent[50];
vector<int> child[50];
void cut(int v)
{
    for(int i=0;i<child[v].size();i++){
        cut(child[v][i]);
    }
    child[v].push_back(-1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> parent[i];
        if(parent[i]==-1) root=i;
        else child[parent[i]].push_back(i);
    }
    cin >> k;
    cut(k);
    if(parent[k]!=-1) child[parent[k]].pop_back();
    for(int i=0;i<n;i++)
        if(child[i].empty()) ans++;
    cout << ans << '\n';
    return 0;
}
