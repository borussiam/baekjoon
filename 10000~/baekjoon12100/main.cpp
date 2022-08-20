#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX = 20;
int N, ans = 2;
vvi board(MAX, vi(MAX, 0));

void check(vvi &m)
{
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(ans < m[i][j]){
                ans = m[i][j];
            }
        }
    }
}

void move(vvi &m, int cnt)
{
    if(cnt == 5){
        check(m);
        return;
    }
    queue<int> q;
    //LEFT
    vvi m_l(MAX, vi(MAX, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(m[i][j]){
                q.push(m[i][j]);
            }
        }
        int j = 0;
        while(!q.empty()){
            if(m_l[i][j] == 0){
                m_l[i][j] = q.front();
            }
            else if(m_l[i][j] != q.front()){
                m_l[i][++j] = q.front();
            }
            else{
                m_l[i][j++] += q.front();
            }
            q.pop();
        }
    }
    move(m_l, cnt+1);
    //RIGHT
    vvi m_r(MAX, vi(MAX, 0));
    for(int i = 0; i < N; i++){
        for(int j = N-1; j >= 0; j--){
            if(m[i][j]){
                q.push(m[i][j]);
            }
        }
        int j = N-1;
        while(!q.empty()){
            if(m_r[i][j] == 0){
                m_r[i][j] = q.front();
            }
            else if(m_r[i][j] != q.front()){
                m_r[i][--j] = q.front();
            }
            else{
                m_r[i][j--] += q.front();
            }
            q.pop();
        }
    }
    move(m_r, cnt+1);
    //UP
    vvi m_u(MAX, vi(MAX, 0));
    for(int j = 0; j < N; j++){
        for(int i = 0; i < N; i++){
            if(m[i][j]){
                q.push(m[i][j]);
            }
        }
        int i = 0;
        while(!q.empty()){
            if(m_u[i][j] == 0){
                m_u[i][j] = q.front();
            }
            else if(m_u[i][j] != q.front()){
                m_u[++i][j] = q.front();
            }
            else{
                m_u[i++][j] += q.front();
            }
            q.pop();
        }
    }
    move(m_u, cnt+1);
    //DOWN
    vvi m_d(MAX, vi(MAX, 0));
    for(int j = 0; j < N; j++){
        for(int i = N-1; i >= 0; i--){
            if(m[i][j]){
                q.push(m[i][j]);
            }
        }
        int i = N-1;
        while(!q.empty()){
            if(m_d[i][j] == 0){
                m_d[i][j] = q.front();
            }
            else if(m_d[i][j] != q.front()){
                m_d[--i][j] = q.front();
            }
            else{
                m_d[i--][j] += q.front();
            }
            q.pop();
        }
    }
    move(m_d, cnt+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            if(ans < board[i][j]){
                ans = board[i][j];
            }
        }
    }
    move(board, 0);
    cout << ans << '\n';
    return 0;
}
