#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    int dist[N][N], e[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> dist[i][j];
            if(dist[i][j] == 0){
                dist[i][j] = INF;
            }
            if(i != j){
                e[i][j] = 1;
            }
            else{
                e[i][j] = 0;
            }
        }
    }
    bool valid = true;
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            if(dist[i][k] == INF){
                continue;
            }
            for(int j = 0; j < N; j++){
                if(i == j || k == j){
                    continue;
                }
                if(dist[i][j] == dist[i][k]+dist[k][j]){
                    e[i][j] = 0;
                }
                else if(dist[i][j] > dist[i][k]+dist[k][j] && dist[i][k] != INF && dist[k][j] != INF){
                    valid = false;
                    break;
                }
            }
            if(!valid){
                break;
            }
        }
        if(!valid){
            break;
        }
    }
    if(valid){
        int ans = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < i; j++){
                ans += dist[i][j]*e[i][j];
            }
        }
        cout << ans << '\n';
    }
    else{
        cout << -1 << '\n';
    }
    return 0;
}
