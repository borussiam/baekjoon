#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool comp(pii &a, pii &b)
{
    return (a.first == b.first) && (a.second == b.second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    char board[N][M];
    pii R, B, O;
    pii adj[N][M][4];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < 4; k++){
                adj[i][j][k] = {-1, -1};
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] == 'R'){
                R = {i, j};
            }
            else if(board[i][j] == 'B'){
                B = {i, j};
            }
            else if(board[i][j] == 'O'){
                O = {i, j};
            }
        }
    }
    // cout << R.first << ' ' << R.second << '\n';
    // cout << B.first << ' ' << B.second << '\n';
    // cout << O.first << ' ' << O.second << '\n';
    for(int i = 1; i < N-1; i++){
        for(int j = 1; j < M-1; j++){
            if(board[i][j] == '#'){
                continue;
            }
            //left
            int nj = j;
            while(board[i][nj-1] != '#' && board[i][nj] != 'O'){
                --nj;
            }
            adj[i][j][0] = {i, nj};
            //right
            nj = j;
            while(board[i][nj+1] != '#' && board[i][nj] != 'O'){
                ++nj;
            }
            adj[i][j][1] = {i, nj};
            //up
            int ni = i;
            while(board[ni-1][j] != '#' && board[ni][j] != 'O'){
                --ni;
            }
            adj[i][j][2] = {ni, j};
            //down
            ni = i;
            while(board[ni+1][j] != '#' && board[ni][j] != 'O'){
                ++ni;
            }
            adj[i][j][3] = {ni, j};
        }
    }
    // for(int i = 1; i < N-1; i++){
    //     for(int j = 1; j < M-1; j++){
    //         cout << adj[i][j][0].first << ' ' << adj[i][j][0].second << " / ";
    //     }
    //     cout << '\n';
    // }
    // return 0;
    int cnt = -1;
    bool success = false;
    queue<pii> qr, qb;
    qr.push(R); qb.push(B);
    while(!success && !qr.empty() && cnt < 10){
        int n = qr.size();
        for(int i = 0; i < n; i++){
            pii curr_r = qr.front(), curr_b = qb.front();
            int r_r = curr_r.first, r_c = curr_r.second;
            int b_r = curr_b.first, b_c = curr_b.second;
            qr.pop(); qb.pop();
            if(comp(curr_b, O)){
                continue;
            }
            if(comp(curr_r, O)){
                success = true;
                break;
            }
            // cout << "TEST:\n";
            // cout << r_r << ' ' << r_c << '\n';
            // cout << b_r << ' ' << b_c << '\n';
            for(int j = 0; j < 4; j++){
                if(comp(adj[r_r][r_c][j], adj[b_r][b_c][j]) && !comp(adj[r_r][r_c][j], O)){
                    if(j == 0){
                        if(r_c < b_c){
                            qr.push(adj[r_r][r_c][j]);
                            qb.push({adj[b_r][b_c][j].first, adj[b_r][b_c][j].second+1});
                        }
                        else{
                            qr.push({adj[r_r][r_c][j].first, adj[r_r][r_c][j].second+1});
                            qb.push(adj[b_r][b_c][j]);
                        }
                    }
                    else if(j == 1){
                        if(r_c > b_c){
                            qr.push(adj[r_r][r_c][j]);
                            qb.push({adj[b_r][b_c][j].first, adj[b_r][b_c][j].second-1});
                        }
                        else{
                            qr.push({adj[r_r][r_c][j].first, adj[r_r][r_c][j].second-1});
                            qb.push(adj[b_r][b_c][j]);
                        }
                    }
                    else if(j == 2){
                        if(r_r < b_r){
                            qr.push(adj[r_r][r_c][j]);
                            qb.push({adj[b_r][b_c][j].first+1, adj[b_r][b_c][j].second});
                        }
                        else{
                            qr.push({adj[r_r][r_c][j].first+1, adj[r_r][r_c][j].second});
                            qb.push(adj[b_r][b_c][j]);
                        }
                    }
                    else{
                        if(r_r > b_r){
                            qr.push(adj[r_r][r_c][j]);
                            qb.push({adj[b_r][b_c][j].first-1, adj[b_r][b_c][j].second});
                        }
                        else{
                            qr.push({adj[r_r][r_c][j].first-1, adj[r_r][r_c][j].second});
                            qb.push(adj[b_r][b_c][j]);
                        }
                    }
                }
                else{
                    qr.push(adj[r_r][r_c][j]);
                    qb.push(adj[b_r][b_c][j]);
                }
            }
        }
        ++cnt;
    }
    if(success){
        cout << cnt << '\n';
    }
    else{
        cout << "-1\n";
    }
    return 0;
}
