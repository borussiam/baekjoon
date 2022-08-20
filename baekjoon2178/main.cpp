#include <bits/stdc++.h>
using namespace std;
const int dy[4]={-1,0,0,1},dx[4]={0,-1,1,0};
int r,c,a[102][102],visit[102][102];
queue<pair<int,int>> q;
queue<int> step;
int bfs(int y,int x)
{
    int num=0;
    bool found=false;
    visit[y][x]=1;
    q.push({y,x});
    step.push(num+1);
    while(!q.empty()){
        y=q.front().first,x=q.front().second,num=step.front();
        q.pop(); step.pop();
        for(int i=0;i<4;i++){
            if(y+dy[i]==r&&x+dx[i]==c){
                found=true;
                break;
            }
            if(a[y+dy[i]][x+dx[i]]==1&&!visit[y+dy[i]][x+dx[i]]){
                visit[y+dy[i]][x+dx[i]]=1;
                q.push({y+dy[i],x+dx[i]});
                step.push(num+1);
            }
        }
        if(found) break;
    }
    return num+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r >> c;
    for(int i=1;i<=r;i++){
        string s;
        cin >> s;
        for(int j=1;j<=c;j++)
            a[i][j]=s[j-1]-'0';
    }
    cout << bfs(1,1);
    return 0;
}
