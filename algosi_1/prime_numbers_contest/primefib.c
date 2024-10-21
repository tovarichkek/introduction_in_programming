#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long longlong;
unsigned long long ma = 1llu << 60;
unsigned long long p;
unsigned long long* arr;

unsigned long long fastpoww(unsigned long long n){
    if(n == 1 || p - 1 == 0){
        return 1;
    }

    __uint128_t g = n % p;

    arr[0] = g;
    unsigned long long pw = 1;
    int step2 = 0;

    while(pw * 2 < (p - 1)){
        g = ((__uint128_t)(g) * g) % p;
        pw *= 2;
        step2++;
        arr[step2] = g;
    }

    unsigned long long pwiter = pw;

    while(pw != p - 1){
        if(pw + pwiter > p - 1)
        {
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
    int k, n;
    scanf("%d%d", &k, &n);
    unsigned long long F[100000] = {};
    int flag = 1;
    unsigned long long max_prime = 0;
    unsigned long long test_count = 100000;

    arr = (long long*)calloc(100, sizeof(unsigned long long));
    F[0] = 0;
    F[1] = 1;
    for(int i = 2; F[i - 1] < ma; i++){
        F[i] = k * F[i - 1] + n * F[i - 2];
    }
    
    for(unsigned long long i = 2; i < 1000 && F[i] != 0; i++){
        p = F[i];
        flag = 1;
        for(unsigned long long i = 0; i < test_count; i++){
            unsigned long long a = ((unsigned long long)rand()) * rand();
            if(fastpoww(a) != 1){
                flag = 0;
                break;
            }
        }
        if(flag){
            max_prime = p;
        }
    }
    printf("%llu\n", max_prime);
    free(arr);
}
