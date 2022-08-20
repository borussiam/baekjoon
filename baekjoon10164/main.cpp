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

ll a[15][15], ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i < 15; i++){
        a[0][i] = a[i][0] = 1;
    }
    for(int i = 1; i < 15; i++){
        for(int j = 1; j < 15; j++){
            a[i][j] = a[i-1][j] + a[i][j-1];
        }
    }
    int N, M, K;
    cin >> N >> M >> K;
    if(K == 0){
        ans = a[N-1][M-1];
    }
    else{
        int r = (K-1)/M, c = (K-1)%M;
        ans = a[r][c] * a[N-r-1][M-c-1];
    }
    cout << ans << '\n';
    return 0;
}
