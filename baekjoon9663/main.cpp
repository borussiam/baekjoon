#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, row[16];

int backtrack(int col)
{
    if(col==N){
        // cout << "FIN\n\n";
        return 1;
    }
    int ret=0;
    for(int i = 0; i < N; i++){
        bool valid = true;
        for(int j = 0; j < col; j++){
            if(i==row[j] || col-j==abs(i-row[j])){
                valid = false;
                break;
            }
        }
        if(!valid){
            continue;
        }
        row[col] = i;
        // cout << "step in: " << col << ' ' << i << '\n';
        ret += backtrack(col+1);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    cout << backtrack(0) << '\n';
    return 0;
}
