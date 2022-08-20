#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 8;
int N, M;
int a[MAX], ans[MAX], check[MAX];

void backtrack(int depth)
{
    if(depth==M){
        for(int i = 0; i < M; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < N; i++){
        if(!check[i]){
            ans[depth] = a[i];
            check[i] = true;
            backtrack(depth+1);
            check[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a, a+N);
    backtrack(0);
    return 0;
}
