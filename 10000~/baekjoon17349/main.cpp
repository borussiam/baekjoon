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
    int a[9], b[9], t[9];
    for(int i = 0; i < 9; i++){
        cin >> b[i] >> a[i];
        --a[i];
    }
    int ans = -1;
    for(int i = 0; i < 9; i++){
        memset(t, -1, sizeof(t));
        b[i] ^= 1;
        bool pos = true;
        for(int j = 0; j < 9; j++){
            if(t[a[j]] == -1){
                t[a[j]] = b[j];
            }
            else if(t[a[j]] != b[j]){
                pos = false;
                break;
            }
        }
        int tmp = -1;
        vector<int> cnt[3];
        if(pos){
            for(int j = 0; j < 9; j++){
                cnt[t[j]+1].pb(j);
            }
            if(cnt[2].size() == 1){
                tmp = cnt[2][0];
            }
            else if(cnt[2].size() == 0 && cnt[0].size() == 1){
                tmp = cnt[0][0];
            }
            else if(cnt[2].size() == 0 && cnt[0].size() > 1){
                ans = -1;
                break;
            }
            else pos = false;
        }
        if(pos && tmp != -1){
            if(ans != -1 && ans != tmp){
                ans = -1;
                break;
            }
            ans = tmp;
        }
        b[i] ^= 1;
    }
    if(ans == -1) cout << "-1\n";
    else cout << ans+1 << '\n';
    return 0;
}
