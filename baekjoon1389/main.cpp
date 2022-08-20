#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, ans, bacon = INF; cin >> N >> M;
    int f[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            f[i][j] = i == j ? 0 : INF;
        }
    }
    for(int i = 0, A, B; i < M; i++){
        cin >> A >> B;
        --A; --B;
        f[A][B] = 1;
        f[B][A] = 1;
    }
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    for(int i = 0; i < N; i++){
        int sum = 0;
        for(int j = 0; j < N; j++){
            sum += f[i][j];
        }
        if(sum < bacon){
            ans = i + 1;
            bacon = sum;
        }
    }
    cout << ans << '\n';
    return 0;
}
