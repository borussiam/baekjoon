#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    int l = 0, r = N-1, l_ans = 0, r_ans = N-1, min_sum = abs(a[0] + a[N-1]);
    while(l < r - 1){
        if(a[l] + a[r] >= 0){
            --r;
        }
        else{
            ++l;
        }
        if(abs(a[l] + a[r]) < min_sum){
            min_sum = abs(a[l] + a[r]);
            l_ans = l; r_ans = r;
        }
    }
    cout << a[l_ans] << ' ' << a[r_ans] << '\n';
    return 0;
}
