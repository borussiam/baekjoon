#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    queue<int> j;
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++) j.push(i);
    cout << "<";
    while(true){
        for(int i=1;i<k;i++){
            j.push(j.front());
            j.pop();
        }
        cout << j.front();
        j.pop();
        if(j.empty()) break;
        cout << ", ";
    }
    cout << ">\n";
    return 0;
}
