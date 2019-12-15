
#include <stdio.h>
#include <stdint.h>

/*
    return the value of the least significant bit that is high in an int
*/
int16_t leastSignificantHighBit(int16_t n)
{
    return n & -n;
}

int main()
{
    int16_t j = 8272;

    printf("%d\n", leastSignificantHighBit(j));

    /*  
        explanation for this example:

        8272 in binary:                     0b0010000001010000
        two's complement of 8272 in binary: 0b1101111110110000

              0b0010000001010000
            & 0b1101111110110000
            ---------------------
            = 0b0000000000010000 = 16
    */
    return 0;
}
