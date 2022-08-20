#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 1e18;

bool chk_idx(int &a, int &b, int fix)
{
    if(a == fix){
        ++a;
    }
    if(b == fix){
        --b;
    }
    if(a == b){
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    ll a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a, a+N);
    int l_ans, r_ans, fix_ans;
    ll min_sum = INF;
    for(int fix = 0; fix < N; fix++){
        int l = 0, r = N-1;
        chk_idx(l, r, fix);
        if(abs(a[l] + a[r] + a[fix]) < min_sum){
            min_sum = abs(a[l] + a[r] + a[fix]);
            l_ans = l; r_ans = r; fix_ans = fix;
        }
        while(l < r-1){
            if(a[l] + a[r] + a[fix] >= 0){
                --r;
            }
            else{
                ++l;
            }
            if(chk_idx(l, r, fix)){
                break;
            }
            if(abs(a[l] + a[r] + a[fix]) < min_sum){
                min_sum = abs(a[l] + a[r] + a[fix]);
                l_ans = l; r_ans = r; fix_ans = fix;
            }
        }
    }
    ll ans[3] = {a[l_ans], a[r_ans], a[fix_ans]};
    sort(ans, ans+3);
    for(int i = 0; i < 3; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
