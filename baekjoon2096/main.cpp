#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, max_col[3] = { 0 }, min_col[3] = { 0 }, temp_max[3], temp_min[3];
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            cin >> temp_max[j];
            temp_min[j] = temp_max[j];
            temp_max[j] += max(max_col[1], (j == 1) ? max(max_col[0], max_col[2]) : max_col[j]);
            temp_min[j] += min(min_col[1], (j == 1) ? min(min_col[0], min_col[2]) : min_col[j]);
        }
        memcpy(max_col, temp_max, 3*sizeof(int));
        memcpy(min_col, temp_min, 3*sizeof(int));
    }
    cout << max(max(max_col[0], max_col[1]), max_col[2]) << ' ' << min(min(min_col[0], min_col[1]), min_col[2]) << '\n';
    return 0;
}
