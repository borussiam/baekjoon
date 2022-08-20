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
    int A, B, V; cin >> A >> B >> V;
    int ans = 1 + (V-A)/(A-B) + (((V-A)%(A-B)) ? 1 : 0);
    cout << ans << '\n';
    return 0;
}
