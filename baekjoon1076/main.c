#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long int num[3],res,ten_power=1;
    char color[3][7], color_list[10][7];
    for(int i=0;i<3;i++)
        scanf("%s",color[i]);
    strcpy(color_list[0],"black");
    strcpy(color_list[1],"brown");
    strcpy(color_list[2],"red");
    strcpy(color_list[3],"orange");
    strcpy(color_list[4],"yellow");
    strcpy(color_list[5],"green");
    strcpy(color_list[6],"blue");
    strcpy(color_list[7],"violet");
    strcpy(color_list[8],"grey");
    strcpy(color_list[9],"white");
    for(int i=0;i<3;i++){
        for(int j=0;j<10;j++){
            if(strcmp(color[i], color_list[j])==0){
                num[i]=j;
                break;
            }
        }
    }
    for(int i=0;i<num[2];i++)
        ten_power*=10;
    res=(num[0]*10+num[1])*ten_power;
    printf("%lld",res);
    return 0;
}
