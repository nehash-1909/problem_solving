/*********************************************************************************************************************************
5.  Different Bits Sum Pairwise
We define f(X, Y) as the number of different corresponding bits in the binary representation of X and Y. 
For example, f(2, 7) = 2, since the binary representation of 2 and 7 are 010 and 111, respectively. The first and the third bit differ, so f(2, 7) = 2.

You are given an array of N positive integers, A1, A2,..., AN. Find sum of f(Ai, Aj) for all pairs (i, j) such that 1 ≤ i, j ≤ N. Return the answer modulo 109+7.
*********************************************************************************************************************************/

// Solution

int Solution::cntBits(vector<int> &A) {
    int ans = 0;
    long long mod = 1000000007;
    for(int i=0;i<31;i++)
    {
        long long count = 0; 
        for(int j=0;j<A.size();j++)
        {
            if(A[j]&(1<<i))
            {
                count++;
            }
            
        }
        ans += (((count) * ((long long)A.size()-count) )*2)%mod;
        if(ans>=mod)
        {
            ans -= mod;
        }
    }

    return ans;
}
