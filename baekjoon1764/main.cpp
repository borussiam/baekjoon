#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    string hear[N], see[M];
    vector<string> ans;
    for(int i = 0; i < N; i++){
        cin >> hear[i];
    }
    for(int i = 0; i < M; i++){
        cin >> see[i];
    }
    sort(hear, hear+N);
    sort(see, see+M);
    for(int i = 0; i < M; i++){
        if(binary_search(hear, hear+N, see[i])){
            ans.push_back(see[i]);
        }
    }
    int n = ans.size();
    cout << n << '\n';
    for(int i = 0; i < n; i++){
        cout << ans[i] << '\n';
    }
    return 0;
}
