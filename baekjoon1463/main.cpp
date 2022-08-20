#include <iostream>
#define INF 1000000

using namespace std;

int memo[1000001];

int f(int n)
{
    if(n==1) return 0;
    if(memo[n]!=0) return memo[n];
    int ret=INF;
    if(n%2==0) ret=1+f(n/2);
    if(n%3==0) ret=min(ret,1+f(n/3));
    if(n%6!=0) ret=min(ret,1+f(n-1));
    memo[n]=ret;
    return ret;
}

int main()
{
    int N;
    cin >> N;
    cout << f(N) << endl;
    return 0;
}
