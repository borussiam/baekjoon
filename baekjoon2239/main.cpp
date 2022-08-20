#include <bits/stdc++.h>

using namespace std;

int s[9][9], pos[9][9][9];

pair<int, int> next(int x, int y)
{
    if(x == 8 && y == 8){
        return {-1, -1};
    }
    int nx, ny;
    nx = (y == 8) ? x+1 : x;
    ny = (y == 8) ? 0 : y+1;
    return {nx, ny};
}

void make_impos(int i, int j, int n)
{
    for(int k = 0; k < 9; k++){
        ++pos[i][k][n];
        ++pos[k][j][n];
    }
    --pos[i][j][n];
    int col = i / 3, row = j / 3;
    for(int k = 0; k < 3; k++){
        for(int l = 0; l < 3; l++){
            ++pos[3*col+k][3*row+l][n];
        }
    }
}

void make_pos(int i, int j, int n)
{
    for(int k = 0; k < 9; k++){
        --pos[i][k][n];
        --pos[k][j][n];
    }
    ++pos[i][j][n];
    int col = i / 3, row = j / 3;
    for(int k = 0; k < 3; k++){
        for(int l = 0; l < 3; l++){
            --pos[3*col+k][3*row+l][n];
        }
    }
}

bool backtrack(int r, int c)
{
    bool ret = false;
    if(r == -1 && c == -1){
        return true;
    }
    int nr = next(r, c).first, nc = next(r, c).second;
    if(s[r][c] != -1){
        ret = backtrack(nr, nc);
        if(ret){
            return true;
        }
        else{
            return false;
        }
    }
    for(int i = 0; i < 9; i++){
        if(pos[r][c][i]){
            continue;
        }
        make_impos(r, c, i);
        s[r][c] = i;
        ret = backtrack(nr, nc);
        if(ret){
            return true;
        }
        make_pos(r, c, i);
        s[r][c] = -1;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i < 9; i++){
        string st; cin >> st;
        for(int j = 0; j < 9; j++){
            int n = st[j] - '0' - 1;
            s[i][j] = n;
            if(s[i][j] == -1){
                continue;
            }
            make_impos(i, j, n);
        }
    }
    // cout << '\n';
    // for(int i = 0; i < 9; i++){
    //     for(int j = 0; j < 9; j++){
    //         for(int k = 0; k < 9; k++)
    //             cout << pos[i][j][k];
    //         cout << ' ';
    //     }
    //     cout << '\n';
    // }
    backtrack(0, 0);
    // cout << '\n';
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << s[i][j]+1;
        }
        cout << '\n';
    }
    return 0;
}
