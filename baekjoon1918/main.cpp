#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<char> st;
    string s; cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i]=='('){
            st.push(s[i]);
        }
        else if('A'<=s[i] && s[i]<='Z'){
            cout << s[i];
        }
        else if(s[i]==')'){
            while(st.top()!='('){
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else if(s[i]=='+' || s[i]=='-'){
            while(!st.empty() && st.top()!='('){
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else{
            while(!st.empty() && st.top()!='+' && st.top()!='-' && st.top()!='('){
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    return 0;
}
