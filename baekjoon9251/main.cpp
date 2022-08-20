#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    a="0"+a;
    b="0"+b;
    int l1=a.size(),l2=b.size();
    int**m=new int*[l2];
    for(int i=0;i<l2;i++) m[i]=new int[l1];
    for(int i=0;i<l2;i++) m[i][0]=0;
    for(int i=0;i<l1;i++) m[0][i]=0;
    for(int i=1;i<l2;i++){
        for(int j=1;j<l1;j++){
            if(b[i]==a[j]){
                m[i][j]=m[i-1][j-1]+1;
            }
            else m[i][j]=max(m[i-1][j],m[i][j-1]);
        }
    }
    cout << m[l2-1][l1-1] << endl;
    return 0;
}
