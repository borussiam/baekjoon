#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
ll dp[51][51][51][51];
const int da[8]={0,0,0,0,1,1,1,1}, db[8]={0,0,1,1,0,0,1,1} ,dc[8]={0,1,0,1,0,1,0,1};

ll f(int s, int a, int b, int c)
{
    // cout << '(' << s << ' ' << a << ' ' << b << ' ' << c << ") called\n";
    if(a < 0 || b < 0 || c < 0) return 0;
    ll &ret = dp[s][a][b][c];
    if(ret != -1) return ret;
    ret = 0;
    if(a == 0 && b == 0 && c == 0){
        if(s == 0) return ret = 1;
        return ret = 0;
    }
    if(a > s || b > s || c > s) return ret = 0;
    for(int i=1;i<8;i++){
        ret += f(s-1, a-da[i], b-db[i], c-dc[i]);
        // cout << ret << '\n';
    }
    ret %= MOD;
    // cout << '(' << s << ' ' << a << ' ' << b << ' ' << c << "): " << ret << '\n';
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    int s, a, b, c;
    cin >> s >> a >> b >> c;
    cout << f(s, a, b, c) << '\n';
    return 0;
}
