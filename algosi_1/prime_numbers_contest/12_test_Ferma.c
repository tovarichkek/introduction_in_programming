#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long p;
unsigned long long* arr;

unsigned long long fastpoww(unsigned long long n){    
    unsigned long long g = n % p;
    arr[0] = g;
    unsigned long long pw = 1;
    int step2 = 0;

    while(pw * 2 < (p - 1)){
        g = (g * g) % p;
        pw *= 2;
        step2++;
        arr[step2] = g;
    }

    unsigned long long pwiter = pw;

    while(pw != p - 1){
        if(pw + pwiter > p - 1){
            pwiter /= 2;
            step2--;
            continue;
        }

        g = (g * arr[step2]) % p;
        pw += pwiter;
    }
    return g;
}

int main(){
    scanf("%llu", &p);
    int flag = 1;
    unsigned long long test_count = 1000000;

    arr = calloc(100, sizeof(unsigned long long));

    for(unsigned long long i = 0; i < test_count; i++){        
        unsigned long long a = ((unsigned long long)rand()) * rand();
        if(fastpoww(a) != 1){
            flag = 0;
            break;
        }
    }
    printf("%d\n", flag);
    free(arr);
}
