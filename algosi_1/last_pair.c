#include <stdio.h>

int main(){
    int count = 0;
    scanf("%d", &count);

    int actual = 0, last = 0, max_ind = 0;
    
    scanf("%d", &last);
    for(int i = 0; i < count - 1; i++){
        scanf("%d", &actual);

        if(actual != last && i > max_ind){            
            max_ind = i;
        }
        last = actual;
    }
    printf("%d\n", max_ind + 1);
    return 0;
}