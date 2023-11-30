/*********************************************************************************************************************************
2. Counting Bits

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> dp(n+1,0);

        for(int i=0;i<=n;i++)
        {
            if(i%2==0)
            {
                dp[i] = dp[i/2];
            }
            else
            {
                dp[i] = dp[i/2] + 1;
            }
        }
        return dp;
    }
};
