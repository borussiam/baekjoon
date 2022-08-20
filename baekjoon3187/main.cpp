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
int r, c, v, k, cv, ck;
bool vis[255][255];
char g[255][255];

void dfs(int i, int j)
{
    vis[i][j] = true;
    if(g[i][j] == 'k') ++ck;
    else if(g[i][j] == 'v') ++cv;
    for(int dir = 0; dir < 4; dir++){
        int ni = i+dr[dir], nj = j+dc[dir];
        if(ni < 0 || ni >= r || nj < 0 || nj >= c) continue;
        if(!vis[ni][nj] && g[ni][nj] != '#'){
            dfs(ni, nj);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> g[i][j];
        }
    }
    for(int i = 1; i < r-1; i++){
        for(int j = 1; j < c-1; j++){
            if(!vis[i][j] && g[i][j] != '#'){
                dfs(i, j);
                if(ck > cv) k += ck;
                else v += cv;
                cv = ck = 0;
            }
        }
    }
    cout << k << ' ' << v << '\n';
    return 0;
}
