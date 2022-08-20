#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    ll P[M], A[N-1][3], road[N], n_pass[N-1];
    fill(road, road+N, 0);
    cin >> P[0];
    for(int i = 1; i < M; i++){
        cin >> P[i];
        if(P[i] > P[i-1]){
            ++road[P[i-1]-1];
            --road[P[i]-1];
        }
        else{
            --road[P[i-1]-1];
            ++road[P[i]-1];
        }
    }
    n_pass[0] = road[0];
    // cout << n_pass[0] << ' ';
    for(int i = 1; i < N-1; i++){
        n_pass[i] = n_pass[i-1] + road[i];
        // cout << n_pass[i] << ' ';
    }
    ll ans = 0;
    for(int i = 0; i < N-1; i++){
        cin >> A[i][0] >> A[i][1] >> A[i][2];
        if(A[i][0] * n_pass[i] < A[i][1] * n_pass[i] + A[i][2]){
            ans += A[i][0] * n_pass[i];
        }
        else{
            ans += A[i][1] * n_pass[i] + A[i][2];
        }
    }
    cout << ans << '\n';
    return 0;
}
