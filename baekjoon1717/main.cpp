#include <bits/stdc++.h>
using namespace std;

int p[1010100];

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
    memset(p, -1, sizeof(p));
    int n,m; cin >> n >> m;
    while(m--){
        int z,a,b; cin >> z >> a >> b;
        if(z==0){
            merge(a, b);
        }
        else if(find(a)==find(b)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
