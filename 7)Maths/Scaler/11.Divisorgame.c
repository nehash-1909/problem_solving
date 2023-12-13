/*********************************************************************************************************************************
11. Divisor game
Scooby has 3 three integers A, B, and C.

Scooby calls a positive integer special if it is divisible by B and it is divisible by C. You need to tell the number of special integers less than or equal to A.
*********************************************************************************************************************************/

// Solution
int Solution::solve(int A, int B, int C) {
    /*
    C = dX
    B = eX
    X <= A
    lcm(A,B)=(A*B)/(gcd(A,B))
    any multiple of lcm less than a A will be the count i.e, ans
    lcm(a,b) = a*b/ gcd(a,b)
    */
    int lcm = (B*C)/(__gcd(B,C));
    if(lcm>A)
        return 0;
    int ans = A/lcm;
    return ans;
}
