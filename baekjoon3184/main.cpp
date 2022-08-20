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

const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};

int R, C, o, v, curr_o, curr_v;
char g[255][255];
bool vis[255][255];

void dfs(int r, int c)
{
    // cout << r << ' ' << c << '\n';
    vis[r][c] = true;
    if(g[r][c] == 'o') ++curr_o;
    else if(g[r][c] == 'v') ++curr_v;
    for(int i = 0; i < 4; i++){
        int nr = r+dr[i], nc = c+dc[i];
        if(0 > nr || nr >= R || 0 > nc || nc >= C) continue;
        if(!vis[nr][nc] && g[nr][nc] != '#'){
            dfs(nr, nc);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cin >> g[i][j];
    for(int i = 1; i < R-1; i++){
        for(int j = 1; j < C-1; j++){
            curr_o = curr_v = 0;
            if(!vis[i][j] && g[i][j] != '#'){
                dfs(i, j);
                if(curr_o > curr_v) o += curr_o;
                else v += curr_v;
                // cout << i << ' ' << j << " : " << o << ' ' << v << '\n';
            }
        }
    }
    cout << o << ' ' << v << '\n';
    return 0;
}
