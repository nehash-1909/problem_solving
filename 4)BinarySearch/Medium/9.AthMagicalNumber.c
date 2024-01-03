/*********************************************************************************************************************************
9. Ath Magical Number

You are given three positive integers, A, B, and C.

Any positive integer is magical if divisible by either B or C.

Return the Ath smallest magical number. Since the answer may be very large, return modulo 109 + 7.

Note: Ensure to prevent integer overflow while calculating.
*********************************************************************************************************************************/
// Solution
int gcd(int B, int C)
{
    if(B==0)
        return C ;

    return gcd(C%B, B) ;
}
int lcm(int B, int C)
{
    return B*C/gcd(B,C);
}

int Solution::solve(int A, int B, int C) {
    /*
        Numbers divisible by B and C in a range of [1,M] is given by:
            M/B + M/C - M/lcm(B,C)
    */
    long long l = min(B,C);
    long long r =  (long long )A*min(B,C);
    long long m;
    long long total_factors;
    long long l_c_m = lcm(B,C);
    const int mod = 1e9+7 ;
    while(l<=r)
    {
        m = (r-l)/2+l;
        total_factors = m/B + m/C;
        total_factors-= m/l_c_m;
        if((total_factors == A)&&((m%B==0)||(m%C==0)))
            return m%mod;
        else if(A>total_factors)
        {
            l = m+1;  
        }
        else
        {
            r = m-1;
        }
    }
    return m%mod;
}
