/*********************************************************************************************************************************
4. Pair Sum divisible by M
Given an array of integers A and an integer B, find and return the number of pairs in A whose sum is divisible by B.

Since the answer may be large, return the answer modulo (109 + 7).

Note: Ensure to handle integer overflow when performing the calculations.
*********************************************************************************************************************************/

// Solution
int Solution::solve(vector<int> &A, int B) {
    // Create a remainder array which has its frequency

    unordered_map<int,int> rem_freq;
    int rem = 0;
    int ans = 0;
    long long  mod = 1e9 +7;
    for(int i=0;i<A.size();i++)
    {
        rem = (A[i])%B;

        ans += rem_freq[(B-rem)%B];

        rem_freq[rem]++;
    } 
    return ans%mod;
}
