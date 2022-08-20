#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

int n,p[10][10];

int f(vector<int>& path,vector<bool>& visited,int currentPrice)
{
    if(path.size()==n){
        if(!p[path.back()][path[0]]) return INF;
        return currentPrice+p[path.back()][path[0]];
    }
    int ret=INF;
    for(int next=0;next<n;next++){
        if(visited[next]||!p[path.back()][next]) continue;
        int now=path.back();
        path.push_back(next);
        visited[next]=true;
        int trying=f(path,visited,currentPrice+p[now][next]);
        ret=min(trying,ret);
        path.pop_back();
        visited[next]=false;
    }
    return ret;
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> p[i][j];
    vector<int> path={0};
    vector<bool> visited(n,false);
    visited[0]=true;
    int ans=0;
    cout << f(path,visited,ans) << endl;
    return 0;
}
