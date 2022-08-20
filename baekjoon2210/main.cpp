#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int dr[4] = {1, 0, 0, -1}, dc[4] = {0, -1, 1, 0};
string g[5][5];
set<string> s;

void dfs(int r, int c, string str)
{
    str.append(g[r][c]);
    if(str.length() == 6){
        s.insert(str);
        return;
    }
    
    for(int i = 0; i < 4; i++){
        if(r+dr[i]<0 || r+dr[i]>=5 || c+dc[i]<0 || c+dc[i]>=5){
            continue;
        }
        dfs(r+dr[i], c+dc[i], str);
    }
}

void dfs_all()
{
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            string st;
            dfs(i, j, st);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> g[i][j];
        }
    }
    dfs_all();
    cout << s.size() << '\n';
    return 0;
}
