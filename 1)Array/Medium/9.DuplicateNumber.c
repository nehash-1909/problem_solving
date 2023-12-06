/*********************************************************************************************************************************
9. Find the Duplicate Number

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

*********************************************************************************************************************************/

// Solution

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int n = nums.size();

        int ans;

        for(int i=0;i<nums.size();i++)
        {
            int index = nums[i]%n;
            nums[index] += n; 
        }

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]/n >= 2 )
            {
                ans = i;
            }
        }

        for(int i=0;i<nums.size();i++)
        {
            int index = nums[i]%n;
            nums[index] -= n; 
        }

        return ans;


        
    }
};
