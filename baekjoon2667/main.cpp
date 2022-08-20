#include <bits/stdc++.h>
using namespace std;
const int dy[4]={-1,0,0,1},dx[4]={0,-1,1,0};
int n,a[27][27];
vector<int> v;
int dfs(int y,int x)
{
    int ret=1;
    a[y][x]=0;
    for(int i=0;i<4;i++){
        if(a[y+dy[i]][x+dx[i]]){
            ret+=dfs(y+dy[i],x+dx[i]);
        }
    }
    return ret;
}
int dfs_all()
{
    int num=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]){
                v.push_back(dfs(i,j));
                num++;
            }
        }
    }
    return num;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        for(int j=1;j<=n;j++){
            a[i][j]=s[j-1]-'0';
        }
    }
    int k=dfs_all();
    sort(v.begin(),v.end());
    cout << k << '\n';
    for(int i=0;i<k;i++)
        cout << v[i] << '\n';
    return 0;
}
