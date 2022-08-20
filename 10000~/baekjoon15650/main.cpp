#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 8;
int N, M;
int ans[MAX];

void backtrack(int depth, int prev)
{
    if(depth==M){
        for(int i = 0; i < M; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = prev+1; i <= N; i++){
        ans[depth] = i;
        backtrack(depth+1, i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    backtrack(0, 0);
    return 0;
}
