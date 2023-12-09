/*********************************************************************************************************************************
9. Smallest XOR

Given two integers A and B, find a number X such that A xor X is minimum possible, and the number of set bits in X equals B<=30.
*********************************************************************************************************************************/

// Solution
int Solution::solve(int A, int B) {
    int x = 0;
    /*
    A^X = min ==> A and X should have almost same bit
    so in order to make it min make sure MSB bits should be same (first loop)
    and LSB bit can be different (second loop)
    */
    for(int i =30;i>=0;i--)
    {
        if(B==0)
            return x;
        if((1<<i)&A)
        {
            x |= (1<<i);
            B--;
        }
    }

    for(int i = 0;i<=30;i++)
    {
        if(B==0)
            return x;
        if(((1<<i)&x) == 0)
        {
            x |= (1<<i);
            B--;
        }
    }
    return x;

}
