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

int h[1050][1050];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    while(N*M > 0){
        int a[N][M];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> a[i][j];
            }
        }
        for(int j = 0; j <= M; j++)
            h[0][j] = (j != M && a[0][j] == 1) ? 1 : 0;
        for(int i = 1; i < N; i++)
            for(int j = 0; j <= M; j++)
                h[i][j] = (j != M && a[i][j] == 1) ? h[i-1][j] + 1 : 0;
        int ans = 0;
        for(int i = 0; i < N; i++){
            stack<pi> st;
            for(int j = 0; j <= M; j++){
                int left = j;
                while(!st.empty() && st.top().se > h[i][j]){
                    ans = max(ans, ((j - st.top().fi) * st.top().se));
                    left = st.top().fi;
                    st.pop();
                }
                st.push({left, h[i][j]});
            }
        }
        cout << ans << '\n';
        cin >> N >> M;
    }
    return 0;
}
