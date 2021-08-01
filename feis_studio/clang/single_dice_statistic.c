#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    int counter[6] = {0};
    int i, j;

    for (i=1; i<=60000;i++) {
        int dices = rand() % 6 + 1;
        counter[dices-1] = counter[dices-1] + 1;
    }

    for (j=1; j<=6; j++) {
        printf("%d: %d \n", j,  counter[j-1]);
    }

    return 0;
}