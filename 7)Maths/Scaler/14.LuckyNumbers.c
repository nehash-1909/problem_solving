/*********************************************************************************************************************************
14. Lucky Numbers
A lucky number is a number that has exactly 2 distinct prime divisors.

You are given a number A, and you need to determine the count of lucky numbers between the range 1 to A (both inclusive).
*********************************************************************************************************************************/

// Solution
vector<int> SieveofEro()
{
    vector<int> sieve(1000002,2);
    vector<bool> prime(1000002,true);
    sieve[0] = 0;
    sieve[1] = 1;
    for(int i=2;i<=500001;i++)
    {
        // i = 2 => 4,6,8,10,12,14,16,18,20
        // i = 3 => 3,6,9,12,15,18,21
        // i = 4 => 8,16,20
        // i = 5 => 5, 10, 15, 20
        // i = 6 => 6, 12, 18
        // i = 7 => 7, 14, 21
        // i = 8 => 8, 16, 24
        // i = 9 => 8, 18
        // i = 10 => 10, 20
        if(prime[i]==true)
        {
            for(int j=i*2;j<=1000002;j=j+i)
            {
                prime[j] = false;
                sieve[j]++;
            }  
        }
    }
    return sieve;
}
int Solution::solve(int A) {
    int ans = 0;
    vector<int> sieve = SieveofEro();
    for(int i=1;i<=A;i++)
    {
        if(sieve[i]==4)
        {
            ans++;
        }
    }
    return ans;
}
