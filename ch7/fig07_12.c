// Fig. 7.12: fig07_12.c
// Attempting to modify data through a
// non-constant pointer to constant data

#include <stdio.h>

void f(const int *x_ptr);

int main(void)
{
    int y;
    
    f(&y); // f attempts illegal modification
}

// x_ptr cannot be used to modify the
// value of the variable to which it points
void f(const int *x_ptr)
{
    ///*x_ptr = 100; // error: cannot modify a const object
}