#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K, ans=0; cin >> N >> K;
    queue<int> q;
    bool visited[100001]={0};
    q.push(N);
    visited[N]=true;
    while(!q.empty()){
        int n = q.size();
        bool found=false;
        for(int i = 0; i < n; i++){
            int curr = q.front();
            q.pop();
            if(curr == K){
                found=true;
                break;
            }
            if(curr-1>=0 && !visited[curr-1]){
                q.push(curr-1);
                visited[curr-1]=true;
            }
            if(curr+1<=100000 && !visited[curr+1]){
                q.push(curr+1);
                visited[curr+1]=true;
            }
            if(curr*2<=100000 && !visited[curr*2]){
                q.push(curr*2);
                visited[curr*2]=true;
            }
        }
        if(found){
            break;
        }
        ++ans;
    }
    cout << ans << '\n';
    return 0;
}
