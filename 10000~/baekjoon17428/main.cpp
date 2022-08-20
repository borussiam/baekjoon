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

const ll MAX = 52;
ll N, K, dp[MAX][MAX], cnt = 0, sub = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[0][0] = 1; dp[1][1] = 1;
    for(int i = 2; i < MAX; i++){
        for(int j = 0; j <= i; j++){
            if((i-j) % 2) continue;
            if(j != 0) dp[i][j] += dp[i-1][j-1];
            if(j != i) dp[i][j] += dp[i-1][j+1];
        }
    }
    cin >> N >> K;
    if(K+1 > dp[N][0]){
        cout << "-1\n";
        return 0;
    }
    for(int i = N; i > 0; i--){
        if(cnt == i){
            for(int j = 0; j < i; j++){
                cout << ")";
            }
            return 0;
        }
        ll cmp = dp[i-1][cnt+1];
        if(cnt == 0 || sub + cmp > K){
            cout << "(";
            ++cnt;
        }
        else{
            cout << ")";
            sub += cmp;
            --cnt;
        }
    }
    return 0;
}
