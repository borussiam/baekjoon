#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define fi first
#define se second
#define pb push_back

int N;
pi A[50];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int B[N];
    for(int i = 0; i < N; i++){
        cin >> A[i].fi;
        A[i].se = i;
    }
    sort(A, A+N);
    for(int i = 0; i < N; i++){
        cout << A[i].se << ' ';
    }
    cout << '\n';
    return 0;
}
