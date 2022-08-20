#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 500;
const ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pii> g[MAX];
    ll dist[MAX];
    fill(dist, dist+MAX, INF);
    dist[0] = 0;
    int N, M; cin >> N >> M;
    for(int i = 0, A, B, C; i < M; i++){
        cin >> A >> B >> C;
        --A; --B;
        g[A].push_back({B, C});
    }
    bool negativeCylce = false;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(auto &p : g[j]){
                int next = p.first, d = p.second;
                if(dist[j] != INF && dist[next] > dist[j] + d){
                    dist[next] = dist[j] + d;
                    if(i==N-1){
                        negativeCylce = true;
                    }
                }
            }
        }
    }
    if(negativeCylce){
        cout << -1 << '\n';
    }
    else{
        for(int i = 1; i < N; i++){
            if(dist[i] != INF){
                cout << dist[i] << '\n';
            }
            else{
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}
