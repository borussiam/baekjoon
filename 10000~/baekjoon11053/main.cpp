#include <iostream>
#define INF 10000

using namespace std;

int n,memo[1005],a[1005];

void binarySearch(int left,int right,int target)
{
    if(left+1==right){
        memo[right]=target;
        return;
    }
    int mid=(left+right)/2;
    if(memo[mid]<target) binarySearch(mid,right,target);
    else if(memo[mid]>target) binarySearch(left,mid,target);
    else return;
}

int main()
{
    for(int i=0;i<1005;i++) memo[i]=INF;
    memo[0]=0;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) binarySearch(0,i,a[i]);
    int l=0;
    while(memo[l+1]!=INF||l>=1000) l++;
    cout << l << endl;
    return 0;
}
