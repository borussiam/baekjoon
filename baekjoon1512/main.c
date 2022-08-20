#include <stdio.h>
#include <stdlib.h>

int convert(char* s,int* a)
{
    int i=0;
    while(s[i]!='\0'){
        if(s[i]=='A')
            a[i]=1;
        else if(s[i]=='T')
            a[i]=2;
        else if(s[i]=='G')
            a[i]=3;
        else if(s[i]=='C')
            a[i]=4;
        i++;
    }
    return i;
}

int max4(int* n)
{
    int max;
    if(n[0]>n[1]) max=n[0];
    else max=n[1];
    if(max<n[2]) max=n[2];
    if(max<n[3]) max=n[3];
    return max;
}

int main()
{
    int m,a[3000]={0},l,ans=0;
    char s[3001];
    scanf("%d",&m);
    scanf("%s",s);
    l=convert(s,a);
    int min_ans=l;
    for(int k=1;k<=m;k++){
        ans=0;
        for(int i=0;i<k;i++){
            int num[4]={0};
            for(int j=0;j<(l+k-i-1)/k;j++){
                int index=a[k*j+i];
                num[index-1]++;
            }
            ans+=(l+k-i-1)/k-max4(num);
        }
        if(min_ans>ans)
            min_ans=ans;
    }
    printf("%d",min_ans);
    return 0;
}
