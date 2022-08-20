#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int b_search(vector<int>& ar, int len, int target)
{
    int l = 0, r = len;
    int m;
    while(l<r){
        m = (l+r)/2;
        if(ar[m]==target){
            break;
        }
        if(ar[m]>target){
            r=m-1;
        }
        if(ar[m]<target){
            l=m+1;
        }
    }
    m = (l+r)/2;
    if(ar[m]==target){
        return m;
    }
    else return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, num=0; cin >> n;
    int a[n];
    vector<int> arr, occ;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    arr.push_back(a[0]);
    occ.push_back(1);
    for(int i = 1; i < n; i++){
        while(i < n && a[i]==a[i-1]){
            ++occ[num];
            ++i;
        }
        if(i==n){
            break;
        }
        arr.push_back(a[i]);
        occ.push_back(1);
        ++num;
    }
    cin >> m;
    for(int i = 0, a; i < m; i++){
        cin >> a;
        int search = b_search(arr, num, a);
        if(search == -1){
            cout << 0 << ' ';
        }
        else{
            cout << occ[search] << ' ';
        }
    }
    return 0;
}
