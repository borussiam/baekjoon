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

int N, M, a[1005], b[1005];

int best(int num)
{
    int idx = -1, end = N;
    for(int i = 0; i < M; i++){
        if(a[i] <= num && num <= b[i] && b[i] < end){
            end = b[i];
            idx = i;
        }
    }
    return idx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--){
        int ans = 0;
        cin >> N >> M;
        for(int i = 0; i < M; i++){
            cin >> a[i] >> b[i];
            --a[i]; --b[i];
        }
        for(int i = 0; i < N; i++){
            int idx = best(i);
            if(idx >= 0){
                ++ans;
                a[idx] = N;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
