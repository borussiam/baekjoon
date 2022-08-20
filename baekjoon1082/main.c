#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,price[10],price_min=51,min_pos,money,arr[50],index=1;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&price[i]);
        if(i!=0&&price[i]<=price_min){
            price_min=price[i];
            min_pos=i;
        }
    }
    scanf("%d",&money);
    if(money<price_min)
        printf("0");
    else{
        arr[0]=min_pos;
        money-=price_min;
        if(price[0]<price_min){
            while(money-price[0]>=0){
                arr[index]=0;
                money-=price[0];
                index++;
            }
        }
        else{
            while(money-price_min>=0){
                arr[index]=min_pos;
                money-=price_min;
                index++;
            }
        }
        for(int i=0;i<index;i++){
            for(int j=N-1;j>arr[i];j--){
                if(money+price[arr[i]]>=price[j]){
                    money=money+price[arr[i]]-price[j];
                    arr[i]=j;
                    break;
                }
            }
            if(money==0)
                break;
        }
        for(int i=0;i<index;i++)
            printf("%d",arr[i]);
    }
    return 0;
}
