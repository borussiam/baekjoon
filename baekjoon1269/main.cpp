#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin >> n >> m;
    set<int> a,b;
    for(int i=0,k;i<n;i++){
        cin >> k;
        a.insert(k);
    }
    for(int i=0,k;i<m;i++){
        cin >> k;
        b.insert(k);
    }
    set<int> p(a),q(b);
    set<int>::iterator iter=b.begin();
    for(iter;iter!=b.end();iter++){
        set<int>::iterator is=p.find(*iter);
        if(is!=p.end()){
            p.erase(is);
        }
    }
    iter=a.begin();
    for(iter;iter!=a.end();iter++){
        set<int>::iterator is=q.find(*iter);
        if(is!=q.end()){
            q.erase(is);
        }
    }
    cout << p.size()+q.size() << '\n';
    return 0;
}
