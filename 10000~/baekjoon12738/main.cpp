#include <bits/stdc++.h>
using namespace std;
const int MIN=-1234567890;

int main()
{
    int n;
    cin >> n;
    int*a=(int*)malloc((n+1)*sizeof(int));
    vector<int> d(1,MIN);
    for(int i=1;i<=n;i++) cin >> a[i];
    a[0]=MIN;
    int len=0;
    for(int i=1;i<=n;i++){
        if(a[i]>d[len]){
            d.push_back(a[i]);
            len++;
        }
        else{
            int idx=lower_bound(d.begin(),d.begin()+len,a[i])-d.begin();
            d[idx]=a[i];
        }
    }
    cout << len << endl;
    return 0;
}
