#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1'000'007;
ll w, h, x, y, arr[205][205]{{1,},};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 1; i < 205; i++){
        arr[i][0] = arr[0][i] = 1;
    }
    for(int i = 1; i < 205; i++){
        for(int j = 1; j < 205; j++){
            arr[i][j] = (arr[i-1][j] + arr[i][j-1]) % MOD;
        }
    }
    cin >> w >> h >> x >> y;
    --w; --h; --x; --y;
    cout << (arr[x][y] * arr[w-x][h-y]) % MOD << '\n';    
    return 0;
}
