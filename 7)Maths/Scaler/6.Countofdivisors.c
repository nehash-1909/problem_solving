/*********************************************************************************************************************************
6. Count of divisors
Given an array of integers A, find and return the count of divisors of each element of the array.

NOTE: The order of the resultant array should be the same as the input array.
*********************************************************************************************************************************/

//Solution


vector<int> SieveofEro()
{
    vector<int> sieve(1000002,2);
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

        for(int j=i*2;j<=1000002;j=j+i)
        {
            
            sieve[j]++;
        }  
    }
    return sieve;
}
vector<int> sieve = SieveofEro();
vector<int> Solution::solve(vector<int> &A) {
    
    int n = A.size();
    
    vector<int> ans(n,0);
    
    for(int i=0;i<n;i++)
    {
        ans[i] = sieve[A[i]];
    }
    return ans;
}
