#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int N, W[16][16], dp[16][1<<16];

int TSP(int curr, int visited)
{
    int &ret = dp[curr][visited];
    if(ret != -1){
        return ret;
    }
    if(visited == (1<<N)-1){
        if(W[curr][0] == 0){
            return INF;
        }
        return W[curr][0];
    }
    ret = INF;
    for(int i = 0; i < N; i++){
        if(visited & (1<<i) || W[curr][i] == 0){
            continue;
        }
        ret = min(ret, TSP(i, visited | (1<<i)) + W[curr][i]);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> W[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << TSP(0, 1) << '\n';
    return 0;
}
