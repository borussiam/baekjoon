#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int dr[4] = {0, 0, 1, -1};
const int dc[4] = {1, -1, 0, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int M, N; cin >> M >> N;
    int a[N][M], tom=0, rip=0;
    queue<int> q;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
            if(a[i][j]>=0){
                ++tom;
                if(a[i][j]==1){
                    ++rip;
                    q.push(M*i+j);
                }
            }
        }
    }
    // cout << tom << ' ' << rip << '\n';
    if(tom==rip){
        cout << 0 << '\n';
        return 0;
    }
    int day=0;
    while(!q.empty()){
        int n = q.size();
        // cout << n << '\n';
        for(int i = 0; i < n; i++){
            int r = q.front() / M;
            int c = q.front() % M;
            q.pop();
            for(int j = 0; j < 4; j++){
                int nr = r + dr[j];
                int nc = c + dc[j];
                if(nr < 0 || N <= nr || nc < 0 || M <= nc){
                    continue;
                }
                if(a[nr][nc]==0){
                    q.push(M*nr+nc);
                    a[nr][nc]=1;
                    ++rip;
                }
            }
        }
        ++day;
        if(tom==rip){
            break;
        }
    }
    if(tom==rip){
        cout << day << '\n';
    }
    else{
        cout << -1 << '\n';
    }
    return 0;
}
