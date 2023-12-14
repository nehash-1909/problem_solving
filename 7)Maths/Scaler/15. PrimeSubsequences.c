/*********************************************************************************************************************************
15. Prime Subsequences
Given an array A having N positive numbers. You have to find the number of Prime subsequences of A.

A Prime subsequence is one that has only prime numbers, for example [2, 3], [5] are the Prime subsequences where [2, 4] and [1, 2, 3, 4] are not.
*********************************************************************************************************************************/

// Solution
const int n = 1e6 + 5;
const long long mod = 1e9+7;
int powPrime(long long a, long long b)
{
    long long ans = 1;
    for(long long i=0;i<b;i++)
    {
        ans = ((ans%mod)*(a%mod))%mod;
    }

    return ans%mod;
}
vector<bool> sieveofEra()
{
    
    vector<bool> isPrime(n+1,true);
    isPrime[0] = false;
    isPrime[1] = false;

    for(int i=2;i<=sqrt(n);i++)
    {
        if(isPrime[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                isPrime[j] = false;
            }

        }
    }
    return isPrime;
}
int Solution::solve(vector<int> &A) {
    long long count = 0;
    vector<bool> isPrime = sieveofEra();
    for(int i=0;i<A.size();i++)
    {
        
        if(isPrime[A[i]])
        {
            // Let M be the number of prime integers in an array, 
            // then the number of Prime Subsequences will be ((2 ^ M) - 1).
            count += 1; 
        }
    }
    return (powPrime(2LL,count)-1 + mod)%mod;   
}
