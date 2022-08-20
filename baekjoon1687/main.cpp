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

int h[350][350];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    int a[N][M];
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        for(int j = 0; j < M; j++){
            a[i][j] = s[j] - '0';
        }
    }

    for(int j = 0; j <= M; j++)
        h[0][j] = (j != M && a[0][j] == 0) ? 1 : 0;
    for(int i = 1; i < N; i++)
        for(int j = 0; j <= M; j++)
            h[i][j] = (j != M && a[i][j] == 0) ? h[i-1][j] + 1 : 0;
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
    return 0;
}
