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
    int dist[N][N]={{0}};
    for(int i = 0; i < N; i++){
        for(int j = 0, k; j < N; j++){
            cin >> dist[i][j];
            if(dist[i][j] == 0){
                dist[i][j] = INF;
            }
        }
    }
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0, k; j < N; j++){
            if(dist[i][j] == INF){
                cout << 0 << ' ';
            }
            else{
                cout << 1 << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
