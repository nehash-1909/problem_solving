/*********************************************************************************************************************************
10. Divide Integers

Divide two integers without using multiplication, division and mod operator.

Return the floor of the result of the division.

Also, consider if there can be overflow cases i.e output is greater than INT_MAX, return INT_MAX.

NOTE: INT_MAX = 2^31 - 1
*********************************************************************************************************************************/

// SOlution

int Solution::divide(int A, int B) {
    long long n = A, m = B;
    long long MAX = 2147483647, MIN = -2147483648;
    int sign = n < 0 ^ m < 0 ? -1 : 1;
    // remove sign of operands
    n = llabs(n), m = llabs(m);
    // q stores the quotient in computation
    long long q = 0, t, i;

    /*
    dividend = answer * divisor + c
    */
    for (t = 0, i = 31; i >= 0; i--)
        if (t + (m << i) <= n)
            t += m << i, q |= 1LL << i;
    // assign back the sign
    if (sign < 0) q = -q;
    // // // check for overflow and return
    return q >= MAX || q < MIN ? MAX : q;
}
