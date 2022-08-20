#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

const int MAX = 987654321;
int dp[10005];
vector<pi> p;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(begin(dp), end(dp), MAX);
    int n; cin >> n;
    for(int i = 0, x, y; i < n; i++){
        cin >> x >> y;
        p.push_back(make_pair(x, abs(y)));
    }
    sort(p.begin(), p.end());
    dp[0] = 0, dp[1] = p[0].second * 2;
    for(int i = 2; i <= n; i++){
        int height = p[i-1].second;
        for(int j = i-1; j >= 0; j--){
            height = max(height, p[j].second);
            dp[i] = min(dp[j] + max(height*2, p[i-1].first-p[j].first), dp[i]);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
