// Fig 5.16: fig05_16.c
// Scoping.

#include <stdio.h>

void use_local(void); // function prototype
void use_static_local(void); // function prototype
void use_global(void); // function prototype

int x = 1; // global variable

int main(void)
{
    int x = 5; // local variable to main

    printf("local x in outer scope of main is %d\n", x);

    { // start new scope
         int x = 7; // local variable to new scope

         printf("local x in inner scope of main is %d\n", x);
    } // end new scope

    printf("local x in outer scope of main is %d\n", x);
    
    use_local(); // use_local has automatic local x
    use_static_local(); // use_static_local has static local x
    use_global(); // use_global uses global x

    use_local(); // use_local reinitializes automatic local x
    use_static_local(); // static local x retains prior value
    use_global(); // global x also retans value
}

// use_local reinitializes local variable x during each call
void use_local(void)
{
    int x = 25; // initialized each time use_local is called

    printf("\nlocal x in use_local is %d after entering use_local\n", x);
    ++x;
    printf("local x in use_local is %d before exiting use_local\n", x);
}

// use_static_local initializes static local variable x only the first time
// the function is called; value of x is saved between calls to this
// function
void use_static_local(void)
{
    // initialized once
    static int x = 50;

    printf("\nlocal static x is %d on entering use_static_local\n", x);
    ++x;
    printf("local static x is %d on exiting use_static_local\n", x);
}

// function use_global modifies global variable x during each call
void use_global(void)
{
    printf("\nglobal x is %d on entering use_global\n", x);
    x += 10;
    printf("global x is %d on exiting use_global\n", x);
}