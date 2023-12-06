/*********************************************************************************************************************************
8. 3Sum Closest

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.
*********************************************************************************************************************************/

// Solution


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int closet = 200000;

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-1;i++)
        {
            int l = i+1;
            int r = nums.size()-1;
            while(l<r)
            {
                int sum = nums[l]+nums[r]+nums[i];
                if(sum == target)
                {
                    return target;
                }
                else if(sum > target)
                {
                    r--;
                }
                else
                {
                    l++;
                }
                if( abs(target-sum)< abs(target-closet))
                {
                    closet = sum;
                }

            }
        }

        return closet;
        
    }
};
