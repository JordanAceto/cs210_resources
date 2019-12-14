#include <stdio.h>
#include <stdint.h>

uint32_t roundUpToPowerOfTwo(uint32_t n)
{
    --n;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    // n |= n >> 32; // add this line back in if you go to 64 bit ints
    ++n;
    return n;
}

int main()
{
    uint32_t q = roundUpToPowerOfTwo(8272);
    printf("%d\n", q);

    /*
        explanation for this example:

        8272 in binary is: 0b0010000001010000

        subtract 1:        0b0010000001001111
        shift right by 1:  0b0001000000100111
        or them together:  0b0011000001101111
        shift right by 2:  0b0000110000011011
        or them together:  0b0011110001111111
        shift right by 4:  0b0000001111000111
        or them together:  0b0011111111111111
        ...etc

        note that in this case all the bits below the original high
        msb are now filled in. as we continue shifting right by 
        powers of two and or'ing the result back in, all bits right
        of the msb are guaranteed to be set to 1

        after all the right shifting and or'ing is done, add 
        one to the result:

        0b0011111111111111 + 1 = 0b0100000000000000

        this is 16384, the next power of two from 8272, huzzah!

        the general idea is: set all the bits to the right of the msb to 
        one, then add 1, which ripples all the way up to one position 
        past the msb, zeroing out everything below

        now, why subtract 1 at the beginning? answer: think about what 
        would happen if n was already a power of 2, you would go up to 
        the next one

        if you want to *always* return a bigger number than you put in,
        then get rid of the --n at the beginning of the function
    */
    return 0;
}
