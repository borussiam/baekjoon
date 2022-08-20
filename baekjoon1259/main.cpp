#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    while(s!="0"){
        int n=s.size();
        bool pal=true;
        for(int i = 0; i < n/2; i++){
            if(s[i]!=s[n-i-1]){
                pal=false;
                break;
            }
        }
        if(pal){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
        cin >> s;
    }
    return 0;
}
