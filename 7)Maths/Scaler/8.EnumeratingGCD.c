/*********************************************************************************************************************************
8. Enumerating GCD
You are given a number A and a number B. Greatest Common Divisor (GCD) of all numbers between A and B inclusive is taken (GCD(A, A+1, A+2 ... B)).
As this problem looks a bit easy, it is given that numbers A and B can be in the range of 10100.

You have to return the value of GCD found.

The greatest common divisor of 2 numbers, A and B, is the largest number, D that divides both A and B perfectly
*********************************************************************************************************************************/

// Solution
string Solution::solve(string A, string B)
{
    // gcd of consecutive number is 1
    if(A==B)
        return A;
    return "1";
}
