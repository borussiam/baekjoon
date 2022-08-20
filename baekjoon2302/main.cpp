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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll p[41] = {1, 1, 2,};
    for(int i = 3; i < 41; i++) p[i] = p[i-1] + p[i-2];
    int N, M; cin >> N >> M;
    int a[M+1], fix = 0, f;
    for(int i = 0; i < M; i++){
        cin >> f;
        a[i] = f-fix-1;
        fix = f;
    }
    a[M] = N-fix;
    ll ans = 1;
    for(int i = 0; i <= M; i++){
        ans *= p[a[i]];
    }
    cout << ans << '\n';
    return 0;
}
