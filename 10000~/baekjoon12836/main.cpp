#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll m[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q; cin >> N >> Q;
    while(Q--){
        ll a, b, c; cin >> a >> b >> c;
        if(a == 1) m[b] += c;
        else{
            ll sum = 0;
            for(int i = b; i <= c; i++)
                sum += m[i];
            cout << sum << '\n';
        }
    }
    return 0;
}