#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX_m = 2e5, MAX_n = 5e5;
int spt[20][MAX_m+1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m; cin >> m;
    int f[m+1];
    for(int i = 1; i <= m; i++){
        cin >> f[i];
    }
    for(int j = 1; j <= m; j++){
        spt[0][j] = f[j];
    }
    for(int i = 1; i < 20; i++){
        for(int j = 1; j <= m; j++){
            spt[i][j] = spt[i-1][spt[i-1][j]];
        }
    }
    int Q; cin >> Q;
    while(Q--){
        int n, x; cin >> n >> x;
        int ans = x;
        for(int i = 0; i < 20; i++){
            if(n % 2){
                ans = spt[i][ans];
            }
            n /= 2;
        }
        cout << ans << '\n';
    }
    return 0;
}
