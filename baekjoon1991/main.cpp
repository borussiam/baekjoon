#include <bits/stdc++.h>
using namespace std;
class Tree{
public:
    int N;
    vector<int> parent;
    vector<int> lc,rc;

    Tree(): N(0){}
    Tree(int n): N(n){
        parent.resize(N,-1);
        lc.resize(N,-1);
        rc.resize(N,-1);
    }

    void setChildren(int p,int l,int r){
        if(l!='.'-'A') parent[l]=p;
        if(r!='.'-'A') parent[r]=p;
        lc[p]=l;
        rc[p]=r;
    }

    void preorder(int root){
        char c=root+'A';
        cout << c;
        if(lc[root]!='.'-'A') preorder(lc[root]);
        if(rc[root]!='.'-'A') preorder(rc[root]);
    }
    void inorder(int root){
        char c=root+'A';
        if(lc[root]!='.'-'A') inorder(lc[root]);
        cout << c;
        if(rc[root]!='.'-'A') inorder(rc[root]);
    }
    void postorder(int root){
        char c=root+'A';
        if(lc[root]!='.'-'A') postorder(lc[root]);
        if(rc[root]!='.'-'A') postorder(rc[root]);
        cout << c;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Tree T(n);
    for(int i=0;i<n;i++){
        char a,b,c;
        cin >> a >> b >> c;
        a-='A'; b-='A'; c-='A';
        T.setChildren(a,b,c);
    }
    T.preorder(0);
    cout << '\n';
    T.inorder(0);
    cout << '\n';
    T.postorder(0);
    cout << '\n';
    return 0;
}
