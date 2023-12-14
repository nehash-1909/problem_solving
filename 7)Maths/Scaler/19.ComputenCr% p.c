/*********************************************************************************************************************************
19. Compute nCr % p
Given three integers A, B, and C, where A represents n, B represents r, and C represents p and p is a prime number greater than equal to n, find and return the value of nCr % p where nCr % p = (n! / ((n-r)! * r!)) % p.

x! means factorial of x i.e. x! = 1 * 2 * 3... * x.

NOTE: For this problem, we are considering 1 as a prime.
*********************************************************************************************************************************/

// Solution
int modInverse(int a, int b, int mod)
{
    if(a==0)
    {
        return 0;
    }
    if(b==0)
    {
        return 1;
    }
    long long temp = modInverse(a,b/2,mod);
    long long ans = ((temp%mod)*(temp%mod))%mod;
    if(b%2==1)
    {
        ans = ((ans%mod)*(a%mod))%mod;
    }
    ans = ((ans%mod) + mod)%mod;
    return ans;
}
int Solution::solve(int A, int B, int C) {
/*
a^p = a (mod p) where p is a prime number.

a^(p-1) = 1 (mod p)

Multiply by an inverse on both sides

a^(p-2) = a^(-1) (mod p).

nCr%p = fact(n)*modInverse(fact(n-r)%p)*modInverse(fact(r)%p)%p
*/
long long fact[1000005];
fact[0] = 1;
for(long long i=1;i<=A;i++)
{
    fact[i] = (fact[i-1]*i)%C;
}
long long ans = (fact[A]%C);
ans = ((ans)*(modInverse(fact[A-B],C-2,C)%C))%C;
ans = ((ans)*(modInverse(fact[B],C-2,C)%C))%C;
return ans;
}


