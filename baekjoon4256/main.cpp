#include <bits/stdc++.h>
using namespace std;
int cnt,n,preorder[1002],inorder[1002],par[1002],lch[1002],rch[1002];
void make(int init,int fin)
{
    int cnt_fix=cnt;
    int idx=find(inorder+init,inorder+fin,preorder[cnt])-inorder;
    if(idx>init){ // left subtree exists
        lch[preorder[cnt_fix]]=preorder[cnt_fix+1];
        par[preorder[cnt_fix+1]]=preorder[cnt_fix];
        cnt++;
        make(init,idx);
    }
    if(idx<fin-1){ // right subtree exists
        rch[preorder[cnt_fix]]=preorder[cnt+1];
        par[preorder[cnt+1]]=preorder[cnt_fix];
        cnt++;
        make(idx+1,fin);
    }
}
void postorder(int v)
{
    if(lch[v]!=-1) postorder(lch[v]);
    if(rch[v]!=-1) postorder(rch[v]);
    cout << v << ' ';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        memset(par,-1,sizeof(par));
        memset(lch,-1,sizeof(lch));
        memset(rch,-1,sizeof(rch));
        cnt=0;
        cin >> n;
        for(int i=0;i<n;i++) cin >> preorder[i];
        for(int i=0;i<n;i++) cin >> inorder[i];
        make(0,n);
        postorder(preorder[0]);
        cout << '\n';
    }
    return 0;
}
