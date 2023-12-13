/*********************************************************************************************************************************
5. Very Large Power
Given two Integers A, B. You have to calculate (A ^ (B!)) % (1e9 + 7).
*********************************************************************************************************************************/

// Solution
long long mod = 1e9 + 7;
int fact(int n, int m)
{
    long long ans = 1;
    for(int i=2;i<=n;i++)
    {
        ans = ((ans%m)*(i%m))%m;
    }
    return ans;
}
int powFunc(int a, int b)
{
    if(a==0)
    {
        return 0;
    }
    if(b==0)
    {
        return 1;
    }
    long long temp = powFunc(a,b/2);
    long long ans = ((temp%mod)*(temp%mod))%mod;
    if(b%2==1)
    {
        ans = ((ans%mod)*(a%mod))%mod;
    }
    ans = ((ans%mod) + mod)%mod;
    return ans;
}
int Solution::solve(int A, int B) {
    // (mod-1) is used accoring to Fermat Little theorem.
    // A^(B!)%p ==> A^(B!%(p-1))%p
    int factAns = fact(B,mod-1);
    int powAns  = powFunc(A,factAns);
    return powAns;
}
