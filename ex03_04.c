// A program that calculate the sum of the integers from 1 to 10

#include <stdio.h>

int main(void){
    unsigned int counter = 1;
    int sum = 0;

    while (counter < 11) {
        sum += counter;
        ++counter;
    }

    printf("The sum of the integers from 1 to 0 is %d", sum);
}