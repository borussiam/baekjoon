#include <iostream>
#define MOD 10007

using namespace std;

int sumof(int*a,int k)
{
    int ret=0;
    for(int i=0;i<k;i++) ret+=*(a+i);
    return ret%MOD;
}

int main()
{
    int n,m[1005][10];
    cin >> n;
    for(int i=0;i<1005;i++) for(int j=0;j<10;j++) m[i][j]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<10;j++)
            m[i][j]=sumof(m[i-1],j+1);
    }
    cout << sumof(m[n],10)%MOD << endl;
    return 0;
}
