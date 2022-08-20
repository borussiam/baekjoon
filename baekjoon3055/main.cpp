#include <bits/stdc++.h>
using namespace std;
const int dr[4]={-1,0,0,1},dc[4]={0,-1,1,0};
int r,c,a[52][52],d_r,d_c,sr,sc,wr,wc,cnt_s[2]={1,0},cnt_w[2]={0,0};
queue<pair<int,int>> q,q_water;
int bfs()
{
    int ret=0;
    bool flag=false;
    while(1){
        ret++;
        while(!q_water.empty()&&cnt_w[0]){
            wr=q_water.front().first; wc=q_water.front().second;
            q_water.pop();
            cnt_w[0]--;
            for(int i=0;i<4;i++){
                if(a[wr+dr[i]][wc+dc[i]]>0){
                    a[wr+dr[i]][wc+dc[i]]=0;
                    q_water.push({wr+dr[i],wc+dc[i]});
                    cnt_w[1]++;
                }
            }
        }
        cnt_w[0]=cnt_w[1]; cnt_w[1]=0;
        while(!q.empty()&&cnt_s[0]){
            sr=q.front().first; sc=q.front().second;
            q.pop();
            cnt_s[0]--;
            for(int i=0;i<4;i++){
                if(sr+dr[i]==d_r&&sc+dc[i]==d_c){
                    flag=true;
                    break;
                }
                if(a[sr+dr[i]][sc+dc[i]]==1){
                    a[sr+dr[i]][sc+dc[i]]=2;
                    q.push({sr+dr[i],sc+dc[i]});
                    cnt_s[1]++;
                }
            }
            if(flag) break;
        }
        cnt_s[0]=cnt_s[1]; cnt_s[1]=0;
        if(flag||(q.empty()&&q_water.empty())) break;
    }
    if(flag) return ret;
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r >> c;
    for(int i=1;i<=r;i++){
        string s;
        cin >> s;
        for(int j=1;j<=c;j++){
            if(s[j-1]=='.'){
                a[i][j]=1;
                continue;
            }
            if(s[j-1]=='*'){
                a[i][j]=0;
                q_water.push({i,j});
                cnt_w[0]++;
                continue;
            }
            if(s[j-1]=='D'){
                a[i][j]=-1;
                d_r=i; d_c=j;
                continue;
            }
            if(s[j-1]=='S'){
                a[i][j]=2;
                q.push({i,j});
                continue;
            }
        }
    }
    int ans=bfs();
    if(ans==-1) cout << "KAKTUS\n";
    else cout << ans << '\n';
    return 0;
}
