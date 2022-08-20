#include <stdio.h>
#include <stdlib.h>

int main()
{
    int memo[1000*10]={1,1,1,1,1,1,1,1,1,1,},number[1000]={10,},T;
    for(int i=1;i<1000;i++){
        memo[i*10+0]=memo[(i-1)*10+7];
        memo[i*10+1]=memo[(i-1)*10+2]+memo[(i-1)*10+4];
        memo[i*10+2]=memo[(i-1)*10+1]+memo[(i-1)*10+3]+memo[(i-1)*10+5];
        memo[i*10+3]=memo[(i-1)*10+2]+memo[(i-1)*10+6];
        memo[i*10+4]=memo[(i-1)*10+1]+memo[(i-1)*10+5]+memo[(i-1)*10+7];
        memo[i*10+5]=memo[(i-1)*10+2]+memo[(i-1)*10+4]+memo[(i-1)*10+6]+memo[(i-1)*10+8];
        memo[i*10+6]=memo[(i-1)*10+3]+memo[(i-1)*10+5]+memo[(i-1)*10+9];
        memo[i*10+7]=memo[(i-1)*10+0]+memo[(i-1)*10+4]+memo[(i-1)*10+8];
        memo[i*10+8]=memo[(i-1)*10+5]+memo[(i-1)*10+7]+memo[(i-1)*10+9];
        memo[i*10+9]=memo[(i-1)*10+6]+memo[(i-1)*10+8];
        for(int j=0;j<10;j++){
            memo[i*10+j]%=1234567;
            number[i]+=memo[i*10+j];
        }
        number[i]%=1234567;
    }

    scanf("%d",&T);
    int N[T];
    for(int i=0;i<T;i++)
        scanf("%d",&N[i]);
    for(int i=0;i<T;i++)
        printf("%d\n",number[N[i]-1]);
    return 0;
}
