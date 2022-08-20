#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, S; cin >> N >> S;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    int s = 0, e = 0, sum = 0, ans = INF;
    while(true){
        if(sum >= S){
            ans = min(ans, e-s);
            sum -= a[s++];
        }
        else if(e == N){
            break;
        }
        else{
            sum += a[e++];
        }
    }
    if(ans == INF){
        cout << "0\n";
    }
    else{
        cout << ans << '\n';
    }
    return 0;
}
