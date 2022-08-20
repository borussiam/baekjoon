#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll M, sum = 0, xr = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M;
    while(M--){
        ll q, x; cin >> q;
        if(q == 1){
            cin >> x;
            sum += x;
            xr ^= x;
        }
        else if(q == 2){
            cin >> x;
            sum -= x;
            xr ^= x;
        }
        else if(q == 3) cout << sum << '\n';
        else cout << xr << '\n';
    }
    return 0;
}
