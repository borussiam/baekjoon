#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    int grid[n][m];
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j]=='B'){
                grid[i][j] = 0;
            }
            else{
                grid[i][j] = 1;
            }
        }
    }
    vector<int> n_change;
    for(int i = 0; i <= n - 8; i++){
        for(int j = 0; j <= m - 8; j++){
            int wrong=0;
            for(int k = i; k < i+8; k++){
                for(int l = j; l < j+8; l++){
                    if(grid[k][l] == (k+l)%2){
                        ++wrong;
                    }
                }
            }
            if(wrong>32){
                wrong = 64-wrong;
            }
            n_change.push_back(wrong);
        }
    }
    cout << *(min_element(n_change.begin(), n_change.end())) << '\n';
    return 0;
}
