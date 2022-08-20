#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, ans=1; cin >> n >> m;
    int grid[n][m];
    bool visited[2][1000][1000]={0};
    visited[0][0][0] = visited[1][0][0] = true;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++){
            grid[i][j] = s[j] - '0';
        }
    }
    queue<piii> q;
    bool reached = false;
    q.push({{0, 0}, grid[0][0]});
    while(!q.empty()){
        int q_size = q.size();
        for(int i = 0; i < q_size; i++){
            bool crashed = q.front().second;
            int r = q.front().first.first;
            int c = q.front().first.second;
            q.pop();
            if(r==n-1 && c==m-1){
                reached = true;
                break;
            }
            for(int j = 0; j < 4; j++){
                int nr = r + dr[j];
                int nc = c + dc[j];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m){
                    continue;
                }
                if(visited[crashed][nr][nc]){
                    continue;
                }
                if(grid[nr][nc]){
                    if(crashed){
                        continue;
                    }
                    visited[1][nr][nc] = true;
                    q.push({{nr, nc}, 1});
                }
                else{
                    visited[crashed][nr][nc] = true;
                    q.push({{nr, nc}, crashed});
                }
            }
        }
        if(reached){
            break;
        }
        ++ans;
    }
    if(reached){
        cout << ans << '\n';
    }
    else{
        cout << -1 << '\n';
    }
    return 0;
}
