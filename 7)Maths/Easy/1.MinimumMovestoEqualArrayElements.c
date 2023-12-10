/*********************************************************************************************************************************
1. Minimum Moves to Equal Array Elements

Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment n - 1 elements of the array by 1.

*********************************************************************************************************************************/

//Solution

class Solution {
public:
    int minMoves(vector<int>& nums) {
        //  If we took a closer look at each operation as well problem statement we will find that
        // increasing all n-1 element except the largest one is similar to decreasing the largest
        // element only. 
        int minVal = *min_element(nums.begin(),nums.end());
        int ans = 0;
        for(auto i:nums)
        {
            ans += (i-minVal);
        }
        return ans;
    }
};
