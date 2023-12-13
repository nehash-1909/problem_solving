/*********************************************************************************************************************************
3.  Prime Modulo Inverse
Given two integers A and B. Find the value of A-1 mod B where B is a prime number and gcd(A, B) = 1.

A-1 mod B is also known as modular multiplicative inverse of A under modulo B.
*********************************************************************************************************************************/

// Solution
int powFunc(int A, int B, int C) {
    // A^-1modB = A^B-2modB
    if(A==0)
    {
        return 0;
    }
    if(B==0)
    {
        return 1;
    }
    long long mul = powFunc(A,B/2,C);
    long long ans = ((mul%C)*(mul%C))%C;
    if(B%2==1)
    {
        ans = ((ans%C)*(A%C))%C;
    }
    ans = ((ans%C )+ C)%C;

    return ans;

}
int Solution::solve(int A, int B) {
    // A^-1modB = A^B-2modB
    int res = powFunc(A,B-2,B);
    return res;

}
