#include <stdio.h>
#include <stdlib.h>
#define DIV 1000000

int main()
{
    int O[1001]={0,1,},OL[1001]={0},L[1001]={0,1,},A[1001]={0,1,},AL[1001]={0},A2[1001]={0},A2L[1001]={0},N[1001]={0,3,};
    for(int i=1;i<1000;i++){
        O[i+1]=O[i]+A[i]+A2[i];
        O[i+1]%=DIV;
        OL[i+1]=OL[i]+L[i]+AL[i]+A2L[i];
        OL[i+1]%=DIV;
        L[i+1]=O[i]+A[i]+A2[i];
        L[i+1]%=DIV;
        A[i+1]=O[i];
        A[i+1]%=DIV;
        AL[i+1]=OL[i]+L[i];
        AL[i+1]%=DIV;
        A2[i+1]=A[i];
        A2[i+1]%=DIV;
        A2L[i+1]=AL[i];
        A2L[i+1]%=DIV;
        N[i+1]=O[i+1]+OL[i+1]+L[i+1]+A[i+1]+AL[i+1]+A2[i+1]+A2L[i+1];
        N[i+1]%=DIV;
    }
    int K;
    scanf("%d",&K);
    printf("%d",N[K]);
    return 0;
}
