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
    int tt; cin >> tt;
    while(tt--){
        int x, y, d; cin >> x >> y;
        d = y - x;
        if(d == 1){
            cout << "1\n";
            continue;
        }
        if(d == 2){
            cout << "2\n";
            continue;
        }
        int k = (int)sqrt(d);
        if(k*k != d) ++k;
        if(k*(k-1) >= d){
            cout << 2*k-2 << '\n';
        }
        else{
            cout << 2*k-1 << '\n';
        }
    }
    return 0;
}
