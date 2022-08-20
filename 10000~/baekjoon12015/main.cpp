#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int*a=(int*)malloc((n+1)*sizeof(int));
    int*d=(int*)calloc((n+1),sizeof(int));
    for(int i=1;i<=n;i++) cin >> a[i];
    a[0]=-1; d[0]=-1;
    int len=0;
    for(int i=1;i<=n;i++){
        if(a[i]>d[len]){
            d[len+1]=a[i];
            len++;
        }
        else{
            int idx=lower_bound(d,d+len,a[i])-d;
            d[idx]=a[i];
        }
    }
    cout << len << endl;
    return 0;
}
