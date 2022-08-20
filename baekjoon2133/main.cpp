#include <iostream>

using namespace std;

int main()
{
    int a[35]={1,0},n;
    for(int i=2;i<=30;i+=2){
        a[i]+=3*a[i-2];
        for(int j=0;j<=i-4;j+=2)
            a[i]+=2*a[j];
    }
    cin >> n;
    cout << a[n] << endl;
    return 0;
}
