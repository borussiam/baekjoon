#include <bits/stdc++.h>

using namespace std;

int p[10005], A[10005];
bool f[10005];

int find(int n)
{
    if(p[n]<0) return n;
    return p[n] = find(p[n]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a==b) return;
    if(A[a]>A[b]){
        p[a] = b;
        f[a]=0;
    }
    else{
        p[b] = a;
        f[b]=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(p,-1,sizeof(p));
    int n,m,k,ans=0; cin >> n >> m >> k;
    for(int i=1;i<=n;i++) f[i]=1;
    for(int i=1;i<=n;i++) cin >> A[i];
//    for(int i=1;i<=n;i++){
//        cout << A[i] << ' ';
//    }
//    cout << '\n';
    for(int i=0,v,w;i<m;i++){
        cin >> v >> w;
        merge(v,w);
    }
//    for(int i=1;i<=n;i++){
//        cout << f[i] << ' ';
//    }
//    cout << '\n';
//    for(int i=1;i<=n;i++){
//        cout << A[i] << ' ';
//    }
//    cout << '\n';
    for(int i=1;i<=n;i++){
        if(f[i]) ans+=A[i];
    }
    if(ans<=k) cout << ans << '\n';
    else cout << "Oh no\n";
    return 0;
}
