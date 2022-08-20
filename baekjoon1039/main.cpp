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

int M;

inline int digit(int n, int i)
{
    while(i--) n /= 10;
    return n%10;
}

inline int swapDigit(int n, int i, int j)
{
    char s[8];
    sprintf(s, "%d", n);
    swap(s[M-i-1], s[M-j-1]);
    sscanf(s, "%d", &n);
    return n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K, ans = -1; cin >> N >> K;
    queue<int> q;
    q.push(N);
    do{
        ++M;
        N /= 10;
    }while(N);
    for(int i = 0; i < K; i++){
        int qSize = q.size();
        bool vis[1000001] = {0};
        for(int j = 0; j < qSize; j++){
            int curr = q.front();
            q.pop();
            for(int k = 0; k < M; k++){
                for(int l = k+1; l < M; l++){
                    if(l < M-1 || digit(curr, k)){
                        int next = swapDigit(curr, k, l);
                        if(!vis[next]){
                            vis[next] = true;
                            q.push(next);
                        }
                    }
                }
            }
        }
    }
    while(!q.empty()){
        if(q.front() > ans) ans = q.front();
        q.pop();
    }
    cout << ans << '\n';
    return 0;
}
