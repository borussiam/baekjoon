#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e6+1;

pii op[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    op[1] = {0, 0};
    for(int i = 2; i < MAX; i++){
        int fi, se;
        if(i%6 == 0){
            if(op[i/3].first <= op[i-1].first && op[i/3].first <= op[i/2].first){
                fi = op[i/3].first + 1;
                se = i/3;
            }
            else if(op[i/2].first <= op[i-1].first){
                fi = op[i/2].first + 1;
                se = i/2;
            }
            else{
                fi = op[i-1].first + 1;
                se = i-1;
            }
        }
        else if(i%2 == 0){
            if(op[i/2].first <= op[i-1].first){
                fi = op[i/2].first + 1;
                se = i/2;
            }
            else{
                fi = op[i-1].first + 1;
                se = i-1;
            }
        }
        else if(i%3 == 0){
            if(op[i/3].first <= op[i-1].first){
                fi = op[i/3].first + 1;
                se = i/3;
            }
            else{
                fi = op[i-1].first + 1;
                se = i-1;
            }
        }
        else{
            fi = op[i-1].first + 1;
            se = i-1;
        }
        op[i].first = fi;
        op[i].second = se;
    }
    int N; cin >> N;
    cout << op[N].first << '\n';
    while(op[N].second){
        cout << N << ' ';
        N = op[N].second;
    }
    cout << "1\n";
    return 0;
}
