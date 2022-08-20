#include <stdio.h>
#include <stdlib.h>

long long power_2(int n)
{
    long long ret=1;
    for(int i=0;i<n;i++)
        ret*=2;
    return ret;
}

int main()
{
    long long A,B,min_multiple[50]={0},how_many_multiples[50]={0},ans=0;
    int power=0;
    scanf("%lld %lld",&A,&B);
    //����ؾ��ϴ� �ִ� �� ���ϱ�
    while(power_2(power+1)<=B)
        power++;
    min_multiple[0]=A;
    //A~B���� 2^i�� ��� �� �ּ��� ���� ����
    for(int i=1;i<=power;i++){
        if(A%power_2(i)==0)
            min_multiple[i]=A;
        else if(power_2(i)-A%power_2(i)<=B-A){
            min_multiple[i]=A+power_2(i)-A%power_2(i);
        }
    }
    how_many_multiples[0]=B-A+1;
    //2^i�� ����� ������ ����
    for(int i=1;i<=power&&min_multiple[i]!=0;i++){
        how_many_multiples[i]=1+(B-min_multiple[i])/power_2(i);
    }
    //�� �� 2^(i+1)�� ����� ������
    for(int i=0;i<power;i++)
        how_many_multiples[i]-=how_many_multiples[i+1];
    for(int i=0;i<=power;i++)
        ans+=how_many_multiples[i]*power_2(i);
    printf("%lld",ans);
    return 0;
}
