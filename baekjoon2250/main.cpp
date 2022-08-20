#include <bits/stdc++.h>
using namespace std;
int n,root,p[10001],l[10001],r[10001],sz[10001],pos[10001][2],visit[10001];
int get_size(int curr)
{
    if(!curr) return 0;
    int &ret=sz[curr];
    if(ret) return ret;
    if(l[curr]==-1&&r[curr]==-1) return ret=1;
    if(l[curr]==-1) return ret=get_size(r[curr])+1;
    if(r[curr]==-1) return ret=get_size(l[curr])+1;
    return ret=get_size(l[curr])+get_size(r[curr])+1;
}
void dfs(int level,int curr,int ppos)
{
    visit[curr]=1;
    int temp=ppos;
    if(level==1) temp=sz[l[curr]]+1;
    else if(l[p[curr]]==curr) temp-=sz[r[curr]]+1;
    else temp+=sz[l[curr]]+1;
    if(temp<pos[level][0]) pos[level][0]=temp;
    if(temp>pos[level][1]) pos[level][1]=temp;
    if(l[curr]&&!visit[l[curr]]) dfs(level+1,l[curr],temp);
    if(r[curr]&&!visit[r[curr]]) dfs(level+1,r[curr],temp);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        cin >> l[a] >> r[a];
        if(l[a]!=-1) p[l[a]]=a;
        else l[a]++;
        if(r[a]!=-1) p[r[a]]=a;
        else r[a]++;
    }
    for(int i=1;i<=n;i++){
        if(!p[i]){
            root=i;
            break;
        }
    }
    for(int i=1;i<=10000;i++) pos[i][0]=10001;
    get_size(root);
    dfs(1,root,-1);
    int lev=1,ans_lev=0,ans_width=0;
    while(pos[lev][1]){
        int k=pos[lev][1]-pos[lev][0]+1;
        if(k>ans_width){
            ans_width=k;
            ans_lev=lev;
        }
        lev++;
    }
    cout << ans_lev << ' ' << ans_width << '\n';
    return 0;
}
