#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define fi first
#define se second
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, M; cin >> N >> M;
    ll p[N], ans = 0;
    for(int i = 0; i < N; i++) cin >> p[i];
    for(int i = 1; i < (1 << N); i++){
        ll prime = 1, cnt = 0;
        for(int j = 0; j < N; j++){
            if(i & (1 << j)){
                prime *= p[j];
                ++cnt;
            }
        }
        if(cnt % 2) ans += M / prime;
        else ans -= M / prime;
    }
    cout << ans << '\n';
    return 0;
}
