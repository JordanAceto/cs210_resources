
#include <stdio.h>
#include <stdint.h> // fixed width integers to make the example explicit

/*
  swap two integers with no temporary variable
*/
void swap(uint16_t* a, uint16_t* b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main()
{

    uint16_t a = 42;
    uint16_t b = 333;

    printf("A before: %d, B before: %d\n", a, b);
    swap(&a, &b);
    printf("A after: %d, B after: %d\n", a, b);

    /*
        explanation of this example:

        42 in binary:  0b0000000000101010 
        333 in binary: 0b0000000101001101

        steps of the funtion in order: 

        *a = *a ^ *b;  

              0b0000000000101010 
            ^ 0b0000000101001101
            ---------------------
            = 0b0000000101100111

        *b = *a ^ *b;

              0b0000000101100111 
            ^ 0b0000000101001101
            ---------------------
            = 0b0000000000101010 <- note that b now contains the original value of a

        *a = *a ^ *b;
        
              0b0000000101100111 
            ^ 0b0000000000101010
            ---------------------
            = 0b0000000101001101 <- note that a now contains the original value of b
        
        a and b are now swapped!
    */

    return 0;
}
