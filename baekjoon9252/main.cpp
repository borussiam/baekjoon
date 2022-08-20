#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b; cin >> a >> b;
    a = "0"+a; b = "0"+b;
    int n = a.size(), m = b.size();
    int dp[n][m];
    for(int i = 0; i < n; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i < m; i++){
        dp[0][i] = 0;
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n-1][m-1] << '\n';
    if(dp[n-1][m-1] == 0){
        return 0;
    }
    int r = n-1, c = m-1;
    stack<char> st;
    while(dp[r][c]){
        if(dp[r][c] != dp[r-1][c] && dp[r][c] != dp[r][c-1] && dp[r][c]-1 == dp[r-1][c-1]){
            st.push(a[r]);
            --r; --c;
            continue;
        }
        if(dp[r][c] == dp[r-1][c]){
            --r;
        }
        else if(dp[r][c] == dp[r][c-1]){
            --c;
        }
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    cout << '\n';
    return 0;
}
