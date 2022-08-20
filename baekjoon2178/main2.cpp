#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
#define fi first
#define se second
#define pb push_back

const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, -1, 0, 1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    queue<pi> bfs;
    int N, M; cin >> N >> M;
    int maze[N][M];
    bool vis[N][M];
    for(int i = 0; i < N; i++){
        fill(vis[i], vis[i]+M, false);
    }
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        for(int j = 0; j < M; j++){
            maze[i][j] = s[j] - '0';
        }
    }
    bfs.push({0, 0});
    int cnt = 1;
    int r = 0; int c = 0;
    vis[0][0] = true;
    while(!bfs.empty()){
        int n = bfs.size();
        for(int k = 0; k < n; k++){
            r = bfs.front().fi; c = bfs.front().se;
            if(r == N-1 && c == M-1) break;
            bfs.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(nr < 0 || nr >= N || nc < 0 || nc >= M || !maze[nr][nc] || vis[nr][nc]) continue;
                bfs.push({nr, nc});
                vis[nr][nc] = true;
            }
        }
        if(r == N-1 && c == M-1) break;
        ++cnt;
    }
    cout << cnt << '\n';
    return 0;
}
