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

int max3(int a, int b, int c)
{
    return max(max(a, b), c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    int a[N][M];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < M; i++){
        for(int j = i+1; j < M; j++){
            for(int k = j+1; k < M; k++){
                int tmp = 0;
                for(int l = 0; l < N; l++){
                    tmp += max3(a[l][i], a[l][j], a[l][k]);
                }
                if(ans < tmp) ans = tmp;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
