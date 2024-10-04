#include <stdio.h>

//eratosfen's algorithm, prome numbers from 2 to N are written im *mass
void prime_to_N(int N, int* mass){
    int numbers[N + 1] = {}; //0 - prime, 1 - compos
    numbers[0] = 1;
    numbers[1] = 1;

    int ind_mass = 0; //index in mass of next prime number
    for(int num = 2; num < N + 1; num++){
        if(numbers[num] == 0){
            mass[ind_mass] = num;
            ind_mass++;
            for(int i = num; i < N + 1; i += num){
                numbers[i] = 1;
            }
        }
    }
}



int main(){
    int N;
    scanf("%d", &N);
    int mass[100] = {};
    prime_to_N(N, mass);
    for(int i = 0; mass[i] != 0; i++){
        printf("%d ", mass[i]);
    }
    printf("\n");
}