#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[128][128];

int cut(int len, int r0, int c0)
{
    if(len==1){
        return a[r0][c0] ? 1 : 100000;
    }
    bool same = true;
    int comp = a[r0][c0];
    for(int i = r0; i < r0+len; i++){
        for(int j = c0; j < c0+len; j++){
            if(a[i][j]!=comp){
                same = false;
                break;
            }
        }
    }
    if(same){
        return comp ? 1 : 100000;
    }
    else{
        return cut(len/2, r0, c0) + cut(len/2, r0, c0+len/2) + cut(len/2, r0+len/2, c0) + cut(len/2, r0+len/2, c0+len/2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    }
    int ans = cut(N, 0, 0);
    cout << ans/100000 << '\n' << ans%100000 << '\n';
    return 0;
}
