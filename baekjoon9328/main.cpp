#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

const int dr[4] = {0, 0, -1, 1}, dc[4] = {-1, 1, 0, 0};
int h, w, ans, vis[102][102];
char b[102][102];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--){
        for(int i = 0; i < 102; i++){
            for(int j = 0; j < 102; j++){
                b[i][j] = '.';
            }
        }
        cin >> h >> w;
        vector<pii> start;
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                cin >> b[i][j];
            }
        }
        string keys; cin >> keys;
        int key_status = 0;
        if(keys != "0"){
            int n_key = keys.size();
            for(int i = 0; i < n_key; i++){
                int alp = keys[i] - 'a';
                key_status |= (1<<alp);
            }
        }
        ans = 0;
        int key_status_mem;
        do{
            queue<pii> q;
            key_status_mem = key_status;
            memset(vis, 0, sizeof(vis));
            q.push({0, 0});
            while(!q.empty()){
                pii curr = q.front();
                int r = curr.first, c = curr.second;
                q.pop();
                if(vis[r][c]){
                    continue;
                }
                vis[r][c] = true;
                if('A' <= b[r][c] && b[r][c] <= 'Z'){
                    int alp = b[r][c] - 'A';
                    if((key_status & (1<<alp)) == 0){
                        continue;
                    }
                }
                if('a' <= b[r][c] && b[r][c] <= 'z'){
                    int alp = b[r][c] - 'a';
                    key_status |= (1<<alp);
                }
                else if(b[r][c] == '$'){
                    ++ans;
                    b[r][c] = '.';
                }
                for(int i = 0; i < 4; i++){
                    int nr = r+dr[i];
                    int nc = c+dc[i];
                    if(nr >= h+2 || nr < 0 || nc >= w+2 || nc < 0 || b[nr][nc] == '*' || vis[nr][nc]){
                        continue;
                    }
                    q.push({nr, nc});
                }
            }
        }while(key_status_mem != key_status);
        cout << ans << '\n';
    }
    return 0;
}
