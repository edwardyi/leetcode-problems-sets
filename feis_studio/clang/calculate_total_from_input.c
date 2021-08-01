#include <stdio.h>

int main() {
    int prices[] = {30, 60, 69, 70, 22};
    
    int total = 0, id;
    while (1) {
        // Please enter id
        scanf("%d", &id);
        if (id == 0) {
            break;
        }

        total += prices[id-1];
    }

    printf("total: %d", total);

    return 0;
}