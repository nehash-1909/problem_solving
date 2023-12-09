/*********************************************************************************************************************************
7. Strange Equality

Given an integer A.
Two numbers, X and Y, are defined as follows:

X is the greatest number smaller than A such that the XOR sum of X and A is the same as the sum of X and A.
Y is the smallest number greater than A, such that the XOR sum of Y and A is the same as the sum of Y and A.
Find and return the XOR of X and Y.
*********************************************************************************************************************************/

// Solution
int Solution::solve(int A) {
    /*
     A + B = (A ^ B) + 2 * (A & B) // standard formula

        If xor and sum is equal, then the AND should be zero from the equation.
        and A&B = 0 means B = A';

    for x: B should be smaller so toggle unset bit of A

    for y: B should be greater so get next 2power of A.    
    */
    int bit = (int) log2(A) + 1;
    int y = 1<<bit;
    int x = 0;
     for (int i = 0; i < bit; i++) {
         if(((1<<i)&A)==0)
         {
             x += (1<<i);
         }
    }

    return x^y;
}
