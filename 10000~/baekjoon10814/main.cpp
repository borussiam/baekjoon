#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> v[201];
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int age; string name;
        cin >> age >> name;
        v[age].push_back(name);
    }
    for(int i = 1; i <= 200; i++){
        int l = v[i].size();
        for(int j = 0; j < l; j++){
            cout << i << ' ' << v[i][j] << '\n';
        }
    }
    return 0;
}
