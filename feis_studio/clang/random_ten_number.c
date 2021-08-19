#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int i,j, n[10], isUsed;
    for (i=1; i<=10; i++) {

        do {
            /** change counter value */
            n[i-1] = rand() % 10 + 1;
            /** reinitial isUsed variable */
            isUsed = 0;
            /** use random number compare each number */
            for (j=1; j<i; j++) {    
                // printf("%d %d %d %d:", i, j, isUsed, n[i-1]);
                /** if number is repeated than while loop will be exected again */
                if (n[i-1] == n[j-1]) {
                    isUsed = 1;
                    break;
                }
            }
        } while (isUsed == 1);

        printf("%d ", n[i-1]);
    }
    printf("\n");

    return 0;
}