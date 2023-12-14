/*********************************************************************************************************************************
18. Compute nCr % m

Given three integers A, B, and C, where A represents n, B represents r, and C represents m, find and return the value of nCr % m where nCr % m = (n!/((n-r)!*r!))% m.

x! means factorial of x i.e. x! = 1 * 2 * 3... * x.
*********************************************************************************************************************************/

//Solution
int Solution::solve(int A, int B, int C) {
    // C(n,r) = C(n-1,r-1) + C(n-1,r)
    //C(n, 0) = C(n, n) = 1
    vector<int> com(B+1,0);
    com[0] = 1;
    for(int i=0;i<=A;i++)
    {
        for(int j=min(i,B);j>0;j--) // min(i,r) as we have to calculate till r only
            com[j]= (com[j-1]%C + com[j]%C)%C;
        }
    }
    return com[B];
}
