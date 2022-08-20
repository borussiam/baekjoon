#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    int dist[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = i==j ? 0 : INF;
        }
    }
    for(int i = 0, a, b, c; i < m; i++){
        cin >> a >> b >> c;
        dist[a-1][b-1] = min(dist[a-1][b-1], c);
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dist[i][j]==INF){
                dist[i][j] = 0;
            }
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
