#include <iostream>

using namespace std;

int memo[11]={0,1,2,4,};

int f(int n)
{
    if(memo[n]!=0) return memo[n];
    return memo[n]=f(n-1)+f(n-2)+f(n-3);
}

int main()
{
    int t;
    cin >> t;
    int a[t];
    while(t--){
        cin >> a[t];
        cout << f(a[t]) << "\n";
    }
    return 0;
}
