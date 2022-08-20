#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b; cin >> a >> b;
    if(a == 1){
        cout << 8*b << '\n';
    }
    else if(a == 5){
        cout << 4 + 8*b << '\n';
    }
    else{
        if(b%2){
            cout << 9 - a + 8*(b/2) << '\n';
        }
        else{
            cout << a - 1 + 8*(b/2) << '\n';
        }
    }
    return 0;
}
