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

const int MAX = 1e5+5;
ll N, a[MAX], ps[MAX][32], bin[MAX][32];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0, k; i < N; i++){
        cin >> k;
        int j = 0;
        while(k){
            bin[i][j] = k % 2;
            k >>= 1;
            ++j;
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 32; j++){
            ps[i][j] = bin[i-1][j] ? i-ps[i-1][j] : ps[i-1][j];
        }
    }
    ll ans = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 32; j++){
            ans += ps[i][j]*(1<<j);
        }
    }
    cout << ans << '\n';
    return 0;
}
