#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,b=0;
    cin >> t;
    while(t--){
        string s;
        int x;
        cin >> s;
        if(s.substr(0,3)=="add"){
            cin >> x;
            x--;
            b|=(1<<x);
        }
        else if(s.substr(0,6)=="remove"){
            cin >> x;
            x--;
            b&=~(1<<x);
        }
        else if(s.substr(0,5)=="check"){
            cin >> x;
            x--;
            cout << (bool)(b&(1<<x)) << '\n';
        }
        else if(s.substr(0,6)=="toggle"){
            cin >> x;
            x--;
            b^=(1<<x);
        }
        else if(s.substr(0,3)=="all"){
            b=(1<<20)-1;
        }
        else if(s.substr(0,5)=="empty"){
            b=0;
        }
    }
    return 0;
}
