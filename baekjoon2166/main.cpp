#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll det(ll x1, ll x2, ll y1, ll y2)
{
    return x1*y2 - x2*y1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    ll p[N+1][2];
    for(int i = 0, x, y; i < N; i++){
        cin >> p[i][0] >> p[i][1];
    }
    p[N][0] = p[0][0];
    p[N][1] = p[0][1];
    ll sum_det = 0;
    for(int i = 0; i < N; i++){
        sum_det += det(p[i][0], p[i][1], p[i+1][0], p[i+1][1]);
    }
    sum_det = abs(sum_det);
    double ans = sum_det/2.0;
    ans = round(ans * 100.0) / 100.0;
    cout << fixed << setprecision(1) << ans << '\n';
    return 0;
}
