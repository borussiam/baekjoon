#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MIN=-1234567890;

bool comp(const pii &a,const pii &b)
{
    return a.first < b.first;
}

int main()
{
    int n;
    cin >> n;
    int*a=(int*)malloc((n+1)*sizeof(int));
    vector<pii> d(1,{MIN,0});
    vector<int> parent(n+1,-1);
    for(int i=1;i<=n;i++) cin >> a[i];
    a[0]=MIN;
    int len=0,last=0;
    for(int i=1;i<=n;i++){
        if(a[i]>d.back().first){
            parent[i]=d.back().second;
            d.push_back(pii(a[i],i));
            len++;
            last=i;
        }
        else{
            int idx=lower_bound(d.begin(),d.begin()+len+1,pii(a[i],0),comp)-d.begin();
            parent[i]=d[idx-1].second;
            d[idx]=pii(a[i],i);
        }
    }
    cout << len << "\n";
    stack<int> seq;
    while(parent[last]!=-1){
        seq.push(a[last]);
        last=parent[last];
    }
    while(!seq.empty()){
        cout << seq.top() << " ";
        seq.pop();
    }
    return 0;
}
