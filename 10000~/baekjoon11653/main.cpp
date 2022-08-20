#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int p=2;
    while(p*p<=n){
        if(n%p==0){
            cout << p << "\n";
            n/=p;
        }
        else p++;
    }
    if(n!=1) cout << n << "\n";
    return 0;
}
