/*********************************************************************************************************************************
11. Jump Game II

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1]
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    int jump(vector<int>& nums) {

        int l = 0;
        int r = 0;
        int ans = 0;

        while( r < nums.size()-1)
        {
            int farthest = 0;
            for(int i=l;i<=r;i++)
            {
                farthest = max(farthest, i+nums[i]);
            }

            l = r+1;
            r = farthest;
            ans +=1;
        }
        return ans;
    }
};
