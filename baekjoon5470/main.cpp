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

const int MAX = 1e6;
ll N, M, h = 0, l = 0, c = 0, ans = 1;
string s;

ll power(ll a, ll b, ll mod = M)
{
    if(a == 0) return 0;
    if(a == 1) return 1;
    if(b == 0) return 1;
    if(b == 1) return a % mod;
    ll ret = 1;
    while(b){
        if(b % 2) ret = (ret * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ret;
}

ll f(int h, int l, int c, int k)
{
    if(h - l > 2) return 0;
    if(h - l == 2){
        if(c == h-1) return power(2, (k+1)/2);
        else return power(2, k/2);
    }
    return (power(2, (k+1)/2) + power(2, k/2) - 1) % M;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> s;
    for(int i = 0; i < N; i++){
        if(s[i] == 'L'){
            ++c;
            h = max(h, c);
        }
        else{
            ans = (ans + f(max(h, c+1), l, c+1, N-i-1)) % M;
            --c;
            l = min(l, c);
        }
    }
    cout << ans << '\n';
    return 0;
}
