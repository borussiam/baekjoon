#include <bits/stdc++.h>

using namespace std;

int p[205];

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
    p[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(p,-1,sizeof(p));
    int n, m; cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            bool is; cin >> is;
            if(is) merge(i,j);
        }
    }
    bool pos = true;
    int a,b; cin >> a;
    for(int i=1;i<m;i++){
        cin >> b;
        if(find(a)!=find(b)){
            pos = false;
            break;
        }
        a = b;
    }
    if(pos) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
