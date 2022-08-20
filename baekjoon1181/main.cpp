#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    pair<int, string> word[n];
    for(int i = 0; i < n; i++){
        cin >> word[i].second;
        word[i].first = word[i].second.size();
    }
    sort(word, word+n);
    cout << word[0].second << '\n';
    for(int i = 1; i < n; i++){
        if(word[i].second!=word[i-1].second){
            cout << word[i].second << '\n';
        }
    }
    return 0;
}
