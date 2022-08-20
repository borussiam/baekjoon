#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    int P[N], t[N+1], ans=0;
    for(int i = 0; i < N; i++){
        cin >> P[i];
    }
    sort(P, P+N);
    t[0]=0;
    for(int i = 1; i < N+1; i++){
        t[i] = t[i-1] + P[i-1];
        ans += t[i];
    }
    cout << ans << '\n';
    return 0;
}
