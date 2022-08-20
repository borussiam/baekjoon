#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    int X[N];
    set<int> s;
    for(int i = 0; i < N; i++){
        cin >> X[i];
        s.insert(X[i]);
    }
    int n=s.size();
    vector<int> S(n);
    set<int>::iterator iter=s.begin();
    for(int i = 0; i < n; i++){
        S[i] = *iter;
        ++iter;
    }
    for(int i = 0; i < N; i++){
        // cout << distance(s.begin(), s.find(X[i])) << ' ';
        cout << lower_bound(S.begin(), S.end(), X[i]) - S.begin() << ' ';
    }
    return 0;
}
