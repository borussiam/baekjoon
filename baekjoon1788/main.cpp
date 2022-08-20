#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1000000000;

ll f_pos[1000100], f_neg[1000100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i < 1000100; i++)
        f_pos[i] = f_neg[i] = MOD+1;
    f_pos[0] = f_neg[0] = 0;
    f_pos[1] = f_neg[1] = 1;
    for(int i = 2; i < 1000100; i++){
        f_pos[i] = (f_pos[i - 1] + f_pos[i - 2])%MOD;
        f_neg[i] = (f_neg[i - 2] - f_neg[i - 1])%MOD;
    }
    // for(int i = 0; i < 100; i++) cout << f_neg[i] << ' ';
    int n; cin >> n;
    if(n > 0){
        cout << 1 << '\n' << f_pos[n] << '\n';
    }
    else if(n < 0){
        n = -n;
        if(f_neg[n] > 0){
            cout << 1 << '\n' << f_neg[n] << '\n';
        }
        else cout << -1 << '\n' << -f_neg[n] << '\n';
    }
    if(n == 0){
        cout << 0 << '\n' << 0 << '\n';
    }
    return 0;
}
