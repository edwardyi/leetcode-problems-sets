#include <stdio.h>
#include <stdlib.h> //malloc

typedef struct {
    int size;
    // int data[1000]; // assume we have 1000 spaces to store data
    int *data;
    // use memory to save time
    int *min;
} Stack;

// create stack
Stack* CreateStack() {
    Stack* s = malloc(sizeof(Stack));
    s->data = NULL; // location of data initialize with null value
    s->min = NULL;
    s->size = 0;
    return s;
}

// return last push number in stack
int TopStack(Stack* s) {
    return s->data[s->size-1];
}

void PopStack(Stack* s) {
    s->size = s->size - 1;
}

void PushStack(Stack* s, int number) {
    // realloc space for data array
    s->data = realloc(s->data, sizeof(int) * (s->size+1));
    s->min = realloc(s->min, sizeof(int) * (s->size + 1));

    // assign number
    s->data[s->size] = number;
    if (s->size == 0 || s->min[s->size-1] < number) {
        s->min[s->size] = number;
    } else {
        s->min[s->size] = s->min[s->size-1];
    }
    
    s->size = s->size + 1;
}

void DestoryStack(Stack* s) {

    // free data to avoid memory leak
    free(s->data);
    free(s->min);
    free(s);
}

// to prevent copy stack to print stack function
void PrintStack(Stack* s) {

    for (int i=0; i<s->size; i++) {

        // printf("%d %d \n", i, s->size);
        printf("%d/%d ", s->data[i], s->size);
    }

    printf("\n");
}

int main(void) {
    // push pop 
    Stack* s = CreateStack();
    // s.size = 0;

    // Passing reference
    PushStack(s, 3);

    // Copy stack to print stack values
    printf("%d \n", TopStack(s));

    PushStack(s, 10);

    printf("%d \n", TopStack(s));

    PopStack(s);

    printf("%d \n", TopStack(s));

    PushStack(s, 11);

    printf("%d \n", TopStack(s));

    PrintStack(s);

    DestoryStack(s);
    
    return 0;
}
