#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4;
int t[MAX+1], outdegree[MAX+1], dp[MAX+1];
vector<int> g[MAX+1], g_inv[MAX+1];

int work(int curr)
{
    // cout << "IN: " << curr << '\n';
    int &ret = dp[curr];
    if(ret != -1){
        return ret;
    }
    ret = t[curr];
    int add = 0;
    for(int &prev : g_inv[curr]){
        add = max(add, work(prev));
    }
    ret += add;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    fill(dp, dp+N+1, -1);
    for(int i = 0, k; i < N; i++){
        cin >> t[i] >> k;
        for(int j = 0, v; j < k; j++){
            cin >> v;
            g_inv[i].push_back(v-1);
            g[v-1].push_back(i);
            ++outdegree[v-1];
        }
    }
    t[N] = 0;
    for(int i = 0; i < N; i++){
        if(outdegree[i] == 0){
            g[i].push_back(N);
            g_inv[N].push_back(i);
        }
    }
    // for(int i = 0; i <= N; i++){
    //     for(int j = 0; j < int(g_inv[i].size()); j++)
    //         printf("%d ", g_inv[i][j]+1);
    //     if(g_inv[i].size() == 0) printf("NONE");
    //     printf("\n");
    // }
    int ans = work(N);
    cout << ans << '\n';
    return 0;
}
