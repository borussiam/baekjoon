#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<pii> vii;

int w,h,visit[52][52]={0},a[52][52]={0};
vii adj[52][52];

void dfs(int r,int c)
{
    visit[r][c]=1;
    for(pii next: adj[r][c])
        if(!visit[next.first][next.second]) dfs(next.first,next.second);
}
int dfs_all()
{
    int ret=0;
    for(int i=1;i<=w;i++){
        for(int j=1;j<=h;j++){
            if(!visit[i][j]){
                ret++;
                dfs(i,j);
            }
        }
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(1){
        cin >> h >> w;
        if(w==0&&h==0) return 0;
        for(int i=1;i<=w;i++){
            for(int j=1;j<=h;j++){
                visit[i][j]=0;
            }
        }
        for(int i=1;i<=w;i++){
            for(int j=1;j<=h;j++){
                cin >> a[i][j];
                if(a[i][j]==0){
                    visit[i][j]=1;
                    continue;
                }
                if(a[i][j-1]==1){
                    adj[i][j-1].push_back({i,j});
                    adj[i][j].push_back({i,j-1});
                }
                if(a[i-1][j-1]==1){
                    adj[i][j].push_back({i-1,j-1});
                    adj[i-1][j-1].push_back({i,j});
                }
                if(a[i-1][j]==1){
                    adj[i][j].push_back({i-1,j});
                    adj[i-1][j].push_back({i,j});
                }
                if(a[i-1][j+1]==1){
                    adj[i][j].push_back({i-1,j+1});
                    adj[i-1][j+1].push_back({i,j});
                }
            }
        }
        cout << dfs_all() << '\n';
    }
}
