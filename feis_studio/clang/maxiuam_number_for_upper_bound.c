#include <stdio.h>

int main ()
{
    int i, n[10];
    // printf("enter 10 numbers");
    // ma

    for (i=1; i<=10; i++) {
        scanf("%d", &n[i-1]); // 1 2 3 ... 10
    }

    while (1) {
        int input_upper,
            max_i = -1;

        printf("Upper Bound:");
        scanf("%d", &input_upper);

        if (input_upper == 0) {
            break;
        }

        for (i=0; i<10; i++) {
            int currentNumber = n[i],
                maxNumber = n[max_i];

            // 1 3 6 7 3 3 1 788 33 99
            //   10 
            //       4
            if (max_i == -1 || (input_upper >= currentNumber && currentNumber > maxNumber) )  {
                max_i = i;
                // printf("%d %d %d %d %d:\n", i, max_i, input_upper, currentNumber, maxNumber);
            }
        }
        
        printf("%d", n[max_i]);

        printf("\n");
    }
    
    return 0;
}