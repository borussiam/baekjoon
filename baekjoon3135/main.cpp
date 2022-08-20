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
    int A, B, N; cin >> A >> B >> N;
    int a[N]; for(int i = 0; i < N; i++) cin >> a[i];
    int ans = abs(B-A);
    for(int i = 0; i < N; i++){
        if(abs(B-a[i]) + 1 < ans) ans = abs(B-a[i]) + 1;
    }
    cout << ans << '\n';
    return 0;
}
