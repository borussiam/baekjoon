#include <bits/stdc++.h>
using namespace std;
int n,m,indegree[32010];
vector<int> v[32010];
priority_queue<int> pq;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        indegree[b]++;
    }
    for(int i=1;i<=n;i++) if(!indegree[i]) pq.push(-i);
    while(!pq.empty()){
        int popped=-pq.top(); pq.pop();
        cout << popped << ' ';
        for(int i=0;i<v[popped].size();i++){
            int nxt=v[popped][i];
            indegree[nxt]--;
            if(!indegree[nxt]) pq.push(-nxt);
        }
    }
    return 0;
}
