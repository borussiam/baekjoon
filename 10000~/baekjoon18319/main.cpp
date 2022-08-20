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

bool cmp(const int x, const int y)
{
    return x > y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K; cin >> N >> K;
    int B[N], C[N];
    for(int i = 0; i < N; i++){
        cin >> B[i];
    }
    sort(B, B+N, cmp);
    int m = 1000, ans = 0;
    for(m = 1000; m >= 1; m--){
        memcpy(C, B, sizeof(B));
        int can = 0;
        for(int i = 0; i < N; i++){
            can += B[i]/m;
            C[i] -= m * (B[i]/m);
        }
        // cout << m << ' ' << can << '\n';
        if(can < K/2) continue;
        sort(C, C+N, cmp);
        // for(int i = 0; i < N; i++) cout << C[i] << ' ';
        // cout << '\n';
        int tmp = m * min(K/2, can - K/2);
        for(int i = 0; i < min(N, K-can); i++) tmp += C[i];
        if(tmp > ans) ans = tmp;
    }
    cout << ans << '\n';
    return 0;
}
