/*********************************************************************************************************************************
1. Climbing Stairs
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    int climbStairs(int n) {

        if( n == 0 || n == 1)
        {
            return 1;
        }

        vector<int> ways(n+1,0);
        ways[0] = 0;
        ways[1] = 1;
        ways[2] = 2;
        for(int i=3;i<=n;i++)
        {
            ways[i] = ways[i-1] + ways[i-2];
        }
        return ways[n];
    }
};
