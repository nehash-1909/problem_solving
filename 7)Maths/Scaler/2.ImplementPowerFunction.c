/*********************************************************************************************************************************
2. Implement Power Function
Implement pow(A, B) % C.
In other words, given A, B and C, Find (AB % C).
*********************************************************************************************************************************/
// Solution

// Do not write code to include libraries, main() function or accept any input from the console.
// Initialization code is already written and hidden from you. Do not write code for it again.

int Solution::pow(int A, int B, int C) {
    // Just write your code below to complete the function. Required input is available to you as the function arguments.
    // Do not print the result or any output. Just return the result via this function.
    // a^n = a^(n/2)*a^(n/2)
    if(A==0)
        return 0;
    if(B==0)
    {
        return 1;
    }
    long long mul = pow(A,B/2,C);
    long long ans = ((mul%C)*(mul%C))%C;
    if(B%2==0)
    {
        return (ans+C)%C;
    }
    return ((ans%C)*A%C + C)%C;

}
