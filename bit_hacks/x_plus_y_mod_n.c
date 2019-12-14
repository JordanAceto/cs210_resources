
#include <stdio.h>
#include <stdint.h>

/*
    assumes that (0 <= x < n) and 0 <= y < n) 
*/
uint16_t x_plus_y_mod_n(uint16_t x, uint16_t y, uint16_t n)
{
    uint16_t z = x + y;
    return z - (n & -(z >= n));
}

int main()
{

    uint16_t res = x_plus_y_mod_n(42, 22, 50);
    printf("%d\n", res);

    /*
        explanation for this example:

        note that:
            the assumtion that (0 <= x < n) and (0 <= y < n) must be true for this to work

            (x + y) % n is equivalent to:
                (x + y) if n is greater than the sum of x and y (modulo does nothing when it is out of range)
                ((x + y) - n) if the sum of x and y is greater than n (take away n to get the remainder)

        two cases:

        when z is less than n:
            -(z >= n) evaluates to 0
            (n & (0)) evaluates to 0
            z - (0) evaluates to z
            so just return z, which is equal to (x + y)

        when z is at least n:
            -(z >= n) evaluates to 0b1111111111111111
            (n & 0b1111111111111111) evaluates to n
            z - n is... wait for it... z - n
            so return z - n, which is equal to (x + y) - n
    */

    return 0;
}
