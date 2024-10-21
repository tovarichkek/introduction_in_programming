#include <stdio.h>

int main(){
    int count = 0;
    printf("Enter the number of digits\n");
    if((scanf("%d", &count) != 1) || (count < 1)){
        printf("Incorrect input\n");
        return 0;
    }

    int actual = 0, last = 0, max_ind = 0;
    printf("Enter numbers\n");
    if(scanf("%d", &last) != 1){
        printf("Incorrect input\n");
        return 0;
    }

    for(int i = 0; i < count - 1; i++){
        if(scanf("%d", &actual) != 1){
            printf("Incorrect input\n");
            return 0;
        }

        if(actual != last && i > max_ind){            
            max_ind = i;
        }
        last = actual;
    }
    if(max_ind == 0){
        printf("No pairs\n");
    }
    else{
        printf("%d\n", max_ind + 1);
    }
    return 0;
}