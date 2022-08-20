#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size();
        stack<int> st;
        bool vps=true;
        for(int i = 0; i < n; i++){
            if(s[i]=='('){
                st.push(1);
            }
            if(s[i]==')'){
                if(st.empty()){
                    vps=false;
                    break;
                }
                st.pop();
            }
        }
        if(!vps || !st.empty()){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    return 0;
}
