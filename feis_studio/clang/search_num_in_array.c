#include <stdio.h>

int main()
{
    int inputs[10] = {0};

    int counter = 0;
    
    int i;

    printf("Input 10 numbers: \n");

    for (i=1; i<=10; i++) {
        printf("%d:", i);
        scanf("%d", &inputs[i-1]);

        counter++;
    }

    int inputId;

    while (1) {
        printf("Q:");
        scanf("%d", &inputId);
        if (inputId == 0) {
            break;
        }

        printf("%d \n", inputs[inputId-1]);
    }

    return 0;
}