#include <iostream>
#define INF 987654321

using namespace std;

int a[100005];

int f(int left, int right)
{
    if(left==right) return a[left];
    int mid=(left+right)/2;
    int ret=max(f(left,mid),f(mid+1,right));
    int max_left=-INF,max_right=-INF;
    int test=0;
    for(int i=mid;i>=left;i--){
        test+=a[i];
        max_left=max(max_left,test);
    }
    test=0;
    for(int i=mid+1;i<=right;i++){
        test+=a[i];
        max_right=max(max_right,test);
    }
    return max(max_left+max_right,ret);
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    cout << f(0,n-1) << endl;
    return 0;
}
