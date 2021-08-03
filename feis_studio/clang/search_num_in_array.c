#include <stdio.h>

int main()
{
    int inputs[10] = {0};

    int counter = 0;
    
    int id,
        i;

    printf("Input 10 numbers: \n");

    while (1) {
        printf("%d:", counter+1);
        scanf("%d", &id);
        if (id == 0) {
            break;
        }

        inputs[counter] = id;
        counter++;
    }

    while (1) {
        printf("Q:");
        scanf("%d", &id);
        if (id == -1) {
            break;
        }

        printf("%d \n", inputs[id]);
    }

    // for (i=0; i<10;i++) {
    //     if (inputs[i]) {
    //         printf("%d \n", inputs[i]);
    //     }
    // }

    return 0;
}