
#include <stdio.h>
#include <stdint.h>

/*
   return the minimum of two integers with no branching
*/
int16_t min(int16_t a, int16_t b)
{
    return b ^ ((a ^ b) & -(a < b));
}

int main()
{
    int16_t a = 42;
    int16_t b = 333;

    printf("The minimum of %d and %d is %d\n", a, b, min(a, b));

    /*
        explanation of this example:

        first, a note about the -(a < b) part:
            (a < b) evaluates to either 0 or 1
            -(0) is still 0, in binary: 0b0000000000000000
            -(1) is all 1 bits in 2's complement, in binary: 0b1111111111111111

        (1) note that y ^ (x ^ y) = x, that is, doing xor twice gets you back to the original number

        when a is less than b:
            -(a < b) evaluates to 0b1111111111111111
            ((a ^ b) & 0b1111111111111111) is just equal to (a ^ b)
            b ^ (a ^ b) is equal to a (by note 1 above)
            therefore a is returned

        when a is not less than b:
            -(a < b) evaluates to 0b0000000000000000
            ((a ^ b) & 0b0000000000000000) is equal to 0b0000000000000000
            b ^ 0b0000000000000000 is equal to b
            therefore b is returned
    */

    return 0;
}
