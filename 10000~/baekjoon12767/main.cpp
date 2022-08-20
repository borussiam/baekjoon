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

int n, k;
int node[55][22], ch[55][22][2];
bool chk[55];

void ins(int i, int idx, int cmp)
{
    if(node[i][idx] > node[i][cmp]){
        if(ch[i][cmp][1] == -1){
            ch[i][cmp][1] = idx;
            return;
        }
        ins(i, idx, ch[i][cmp][1]);
    }
    else{
        if(ch[i][cmp][0] == -1){
            ch[i][cmp][0] = idx;
            return;
        }
        ins(i, idx, ch[i][cmp][0]);
    }
}

bool cmp(int i, int j, int iidx, int jidx)
{
    if(iidx == -1 && jidx == -1) return true;
    if(iidx == -1 || jidx == -1) return false;
    bool ret = true;
    ret &= cmp(i, j, ch[i][iidx][0], ch[j][jidx][0]);
    ret &= cmp(i, j, ch[i][iidx][1], ch[j][jidx][1]);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(ch, -1, sizeof(ch));
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cin >> node[i][j];
            if(j == 0) continue;
            ins(i, j, 0);
        }
    }
    int ans = n;
    for(int i = 0; i < n; i++){
        if(chk[i]) continue;
        for(int j = i+1; j < n; j++){
            if(chk[j]) continue;
            if(cmp(i, j, 0, 0)){
                --ans;
                chk[j] = true;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
