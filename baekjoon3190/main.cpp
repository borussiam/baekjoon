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

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int board[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K, L; cin >> N >> K;
    for(int i = 0, a, b; i < K; i++){
        cin >> a >> b;
        --a; --b;
        board[a][b] = 1;
    }
    cin >> L;
    int t[L+1]; char dir[L];
    for(int i = 0; i < L; i++){
        cin >> t[i] >> dir[i];
    }
    t[L] = 100000;
    int r = 0, c = 0, d = 0, time = 1;
    deque<pi> body; body.pb({0, 0});
    for(int i = 0; i <= L; i++){
        while(time <= t[i]){
            // cout << "\n\n\n";
            // cout << body.back().fi << ' ' << body.back().se << '\n';
            int nr = body.back().fi+dr[d], nc = body.back().se+dc[d];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N){
                // cout << "dead1";
                cout << time << '\n';
                return 0;
            }
            for(auto p : body){
                // cout << p.fi << ' ' << p.se << '\n';
                if(p.fi ==  nr && p.se == nc){
                    // cout << nr << ' ' << nc << '\n';
                    cout << time << '\n';
                    return 0;
                }
            }
            // cout << '\n';
            body.pb({nr, nc});
            if(board[nr][nc] != 1) body.pop_front();
            else board[nr][nc] = 0;
            ++time;
        }
        d = (dir[i] == 'L') ? ((d+3)%4) : ((d+1)%4);
    }
    return 0;
}
