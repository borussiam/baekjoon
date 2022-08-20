#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d",&N);
    int h[N],m[N],s[N],h_bin[N*6],m_bin[N*6],s_bin[N*6];
    for(int i=0;i<N;i++)
        scanf("%02d:%02d:%02d",&h[i],&m[i],&s[i]);
    for(int i=0;i<N;i++){
        for(int j=0;j<6;j++){
            h_bin[i*6+j]=h[i]%2;
            m_bin[i*6+j]=m[i]%2;
            s_bin[i*6+j]=s[i]%2;
            h[i]/=2;
            m[i]/=2;
            s[i]/=2;
        }
        for(int j=5;j>=0;j--){
            printf("%d%d%d",h_bin[i*6+j],m_bin[i*6+j],s_bin[i*6+j]);
        }
        printf(" ");
        for(int k=5;k>=0;k--)
            printf("%d",h_bin[i*6+k]);
        for(int k=5;k>=0;k--)
            printf("%d",m_bin[i*6+k]);
        for(int k=5;k>=0;k--)
            printf("%d",s_bin[i*6+k]);
        printf("\n");
    }
    return 0;
}
