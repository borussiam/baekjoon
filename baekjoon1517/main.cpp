#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
#define fi first
#define se second
#define pb push_back

const int MAX = 6e5;
int N, A[MAX], B[MAX];
ll inv = 0;

void merge(int l, int m, int r)
{
    int i = l, j = m, k = l;
    while(i < m && j < r){
        if(A[i] <= A[j]) B[k++] = A[i++];
        else{
            B[k++] = A[j++];
            inv += m-i;
        }
    }
    while(i < m) B[k++] = A[i++];
    for(int p = l; p < k; p++) A[p] = B[p];
}

void merge_sort()
{
    for(int k = 2; k < N*2; k *= 2){
        for(int i = 0; i < N; i += k){
            if(i+k <= N) merge(i, (i*2+k)/2, i+k);
            else merge(i, i+k/2, N);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    merge_sort();
    cout << inv << '\n';
    return 0;
}
