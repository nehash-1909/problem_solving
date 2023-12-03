/*********************************************************************************************************************************
1. Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
*********************************************************************************************************************************/

//Solution

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int m = 0;
        int r = nums.size()-1;
        while(m<=r)
        {
            if(nums[m]==0)
            {
                swap(nums[l],nums[m]);
                m++;
                l++;
            }
            else if(nums[m]==1)
            {
                m++;
            }
            else
            {
                swap(nums[m],nums[r]);
                r--;
            }
        }
        
    }
};
