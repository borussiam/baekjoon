#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin >> n >> m;
    string word[n+1];
    map<string,int> word_rev;
    for(int i=1;i<=n;i++){
        string poke; cin >> poke;
        word[i]=poke;
        word_rev.insert({poke,i});
    }
    for(int i=0;i<m;i++){
        string q; cin >> q;
        if(0<=q[0]-'0'&&q[0]-'0'<10){
            int num=0;
            for(int j=0;j<q.size();j++){
                num=10*num+q[j]-'0';
            }
            cout << word[num] << '\n';
        }
        else{
            map<string,int>::iterator iter=word_rev.find(q);
            cout << iter->second << '\n';
        }
    }
    return 0;
}
