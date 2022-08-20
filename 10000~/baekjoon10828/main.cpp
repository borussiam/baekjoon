#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<int> st;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        if(s == "push"){
            int k; cin >> k;
            st.push(k);
        }
        else if(s =="pop"){
            if(st.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if(s == "size"){
            cout << st.size() << '\n';
        }
        else if(s == "empty"){
            cout << st.empty() << '\n';
        }
        else if(s == "top"){
            if(st.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << st.top() << '\n';
            }
        }
    }
    return 0;
}
