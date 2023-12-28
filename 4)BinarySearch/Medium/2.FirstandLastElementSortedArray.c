/*********************************************************************************************************************************
2. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    int searchOcuurence(vector<int>& nums, int target, bool firstOcuurence)
    {
        int l = 0;
        int r = nums.size()-1;
        int ans = -1;
        while(l<=r)
        {
            /*
                       0 1 2 3 4 5
               nums = [5,7,7,8,8,10]
               l = 0;
               r = 5;
               m = 2
               nums[2] = 7 < target
               --------------------
               l = 2+1 = 3
               r  = 5
               m = (5+3)/2 = 4
               nums[4] = 8 == target
               ans = 4
               ----------------------
               r = 4-1 = 3
               l = 3
               m = (3+3)/2 = 3
               nums[3] = 8 == target
               ans = 3
               ----------------------
               r = 2
               l = 3
               r<l break

            */
            int m = (l+r)/2;
            if(nums[m]==target)
            {
                ans = m;
                if(firstOcuurence)
                {
                    r = m-1;
                }
                else
                {
                    l = m+1;
                }
            }
            else if(nums[m]>target)
            {
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        ans[0] = searchOcuurence(nums,target,true);
        ans[1] = searchOcuurence(nums,target,false);
        return ans;
    }
};
