#include <bits/stdc++.h>
using namespace std;

int n,k,w[102],v[102],**memo;

int pack(int item,int weight)
{
    if(item==n) return 0;
    int &ret=memo[item][weight];
    if(ret!=-1) return ret;
    ret=0;
    ret=pack(item+1,weight);
    if(weight>=w[item])
        ret=max(pack(item+1,weight-w[item])+v[item],ret);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    memo=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        memo[i]=(int*)malloc((k+1)*sizeof(int));
        for(int j=0;j<=k;j++) memo[i][j]=-1;
    }
    for(int i=0;i<n;i++) cin >> w[i] >> v[i];
    cout << pack(0,k) << '\n';
    return 0;
}
