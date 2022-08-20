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
    int N, M; cin >> N >> M;
    int a[N];
    for(int i = 0; i < N; i++) cin >> a[i];
    sort(a, a+N);
    int s = 0, e = N-1, ans = 0;
    while(s < e){
        if(a[s] + a[e] > M){
            --e;
        }
        else if(a[s] + a[e] < M){
            ++s;
        }
        else{
            ++ans;
            ++s;
            --e;
        }
    }
    cout << ans << '\n';
    return 0;
    
}
