#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
} Foo;

typedef struct
{
    Foo* baz;
} Bar;


int main() 
{
    // method 1
    {
        // declare address from foo
        Foo foo;
        // declare address from bar
        Bar bar;
        // set struct baz from foo address
        bar.baz = &foo;

        // assign bar address value
        (*bar.baz).data = 100;

        printf("%d \n", (*bar.baz).data);
    }


    // method 2
    {
        // declare address from foo
        Foo foo;
        // declare address from bar
        Bar bar; 
        // get address from bar and assign to footBarPointer
        Bar* footBarPointer = &bar;
        // assign foo address from foo for baz
        (*footBarPointer).baz = &foo;

        // same effect as footBarPointer->baz->data = 100;
        (*(*footBarPointer).baz).data = 1000;
        printf("%d \n", footBarPointer->baz->data);
    }

    return 0;
}