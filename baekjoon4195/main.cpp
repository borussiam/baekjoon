#include <bits/stdc++.h>

using namespace std;

vector<int> p;
vector<string> name;
map<string, int> M;

int find(int n)
{
    if(p[n]<0) return n;
    return p[n] = find(p[n]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
//    cout << a << ' ' << b << '\n';
    if(a == b) return;
    p[b] += p[a];
    p[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
//        cout << name.size() << '\n';
        int f; cin >> f;
        while(f--){
            string n1, n2; int p1, p2;
            cin >> n1 >> n2;
            if(M.find(n1)==M.end()){
//                cout << name.size() << '\n';
                M.insert({n1, name.size()});
                p1 = name.size();
                name.push_back(n1);
                p.push_back(-1);
            }
            else{
                auto iter = M.find(n1);
                p1 = iter->second;
            }
            if(M.find(n2)==M.end()){
                M.insert({n2, name.size()});
                p2 = name.size();
                name.push_back(n2);
                p.push_back(-1);
            }
            else{
                auto iter = M.find(n2);
                p2 = iter->second;
            }
//            cout << p1 << ' ' << p2 << '\n';
            merge(p1, p2);
            cout << -p[find(p1)] << '\n';
        }
        if(f){
            p.clear(); name.clear(); M.clear();
        }
    }
    return 0;
}
