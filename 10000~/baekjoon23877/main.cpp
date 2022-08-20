#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
#define fi first
#define se second
#define pb push_back

const ll MAX_N = 2e5+5, MAX_M = 5e3+3;
ll N, M, ans, psum_s[MAX_M*2], psum_e[MAX_M*2], dup_s[MAX_M], dup_e[MAX_M];
vector<pi> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        ll a, b;
        cin >> a >> b;
        v.pb({a, b});
        ++dup_s[a];
        ++dup_e[b];
    }
    for(int i = 0; i <= M; i++){
        for(int j = 0; j <= M; j++){
            psum_s[i+j] += dup_s[i] * dup_s[j];
        }
    }
    for(int i = 0; i <= M; i++){
        for(int j = 0; j <= M; j++){
            psum_e[i+j] += dup_e[i] * dup_e[j];
        }
    }
    for(int i = 0; i <= M*2; i++){
        ans += psum_s[i];
        cout << ans << '\n';
        ans -= psum_e[i];
    }
    return 0;
}
