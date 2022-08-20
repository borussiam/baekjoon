#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, input;
    scanf("%d", &n);
    scanf("%d", &input);
    int min = input, max = input;
    for(int i=1;i<n;i++){
        scanf("%d", &input);
        if(input>max){
            max = input;
        }
        if(input<min){
            min = input;
        }
    }
    printf("%d %d", min, max);
    return 0;
}
