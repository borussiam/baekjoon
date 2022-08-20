#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0, alph[26]={0}, which, max_alph=0, max_times=0, flag=0;
    char a[1000001];
    scanf("%s", a);
    while(a[i]!='\0'){
        if(a[i]<=90){
            which=a[i]-65;
            alph[which]++;
        }
        else{
            which=a[i]-97;
            alph[which]++;
        }
        i++;
    }

    for(i=0;i<26;i++){
        if(alph[i]==max_times){
            flag=1;
        }
        else if(alph[i]>max_times){
            max_alph=i;
            max_times=alph[i];
            flag=0;
        }
    }

    if(flag==1){
        printf("?");
    }
    else{
        printf("%c", max_alph+65);
    }

    return 0;
}
