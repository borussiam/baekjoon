#include <iostream>

using namespace std;

int memo[1001]={0,1,2,};

int f(int n)
{
    if(memo[n]!=0) return memo[n];
    int ret=(f(n-1)+f(n-2))%10007;
    return memo[n]=ret;
}

int main()
{
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
