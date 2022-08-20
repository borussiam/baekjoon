#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    int s = 0, e = 0, sum = 0, ans = 0;
    while(s < N){
        if(sum >= M){
            sum -= A[s++];
        }
        else if(e == N){
            break;
        }
        else{
            sum += A[e++];
        }
        if(sum == M){
            ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}
