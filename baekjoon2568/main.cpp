#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;

bool comp(const pii &a,const pii &b)
{
    return a.first<b.first;
}

int main()
{
    int n,len=0,last=0;
    cin >> n;
    vii a{pii(-1,-1)},d{pii(-1,0)};
    vi p(n+1,-1);
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        a.push_back(pii(x,y));
    }
    sort(a.begin(),a.end());
    for(int i=1;i<=n;i++){
        if(a[i].second>d.back().first){
            p[i]=d.back().second;
            d.push_back(pii(a[i].second,i));
            len++;
            last=i;
        }
        else{
            int idx=lower_bound(d.begin(),d.begin()+len,pii(a[i].second,0),comp)-d.begin();
            d[idx]=pii(a[i].second,i);
            p[i]=d[idx-1].second;
        }
    }
    cout << n-len << '\n';
    vi seq;
    while(last!=-1){
        while(a.back().second!=a[last].second){
            seq.push_back(a.back().first);
            a.pop_back();
        }
        last=p[last];
        a.pop_back();
    }
    while(!a.empty()){
        seq.push_back(a.back().first);
        a.pop_back();
    }
    seq.pop_back();
    sort(seq.begin(),seq.end()+1);
    for(int i=0;i<n-len;i++) cout << seq[i] << '\n';
    return 0;
}
