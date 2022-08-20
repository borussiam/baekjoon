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
    int N; cin >> N;
    ll A[N+1], sum[N+1] = {0};
    for(int i = 0; i < N; i++) cin >> A[i];
    A[N] = 0;
    for(int i = 1; i <= N; i++) sum[i] = sum[i-1] + A[i-1];
    ll ans = 0;
    stack<pl> s;
    for(int i = 0; i <= N; i++){
        ll left = i;
        while(!s.empty() && s.top().se > A[i]){
            ans = max(ans, (sum[i] - sum[s.top().fi]) * s.top().se);
            left = s.top().fi;
            s.pop();
        }
        s.push({left, A[i]});
    }
    cout << ans << '\n';
    return 0;
}
