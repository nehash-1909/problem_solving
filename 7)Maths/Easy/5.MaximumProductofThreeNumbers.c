/*********************************************************************************************************************************
5. Maximum Product of Three Numbers

Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

*********************************************************************************************************************************/

// Solution
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max_1 = INT_MIN;
        int max_2 = INT_MIN;
        int max_3 = INT_MIN;
        int min_1 = INT_MAX;
        int min_2 = INT_MAX;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>max_1)
            {
                int temp1 = max_1;
                int temp2 = max_2;
                max_1 = nums[i];
                max_2 = temp1;
                max_3 = temp2; 

            }
            else if(nums[i]>max_2)
            {
                int temp1 = max_2;
                max_2 = nums[i];
                max_3 = temp1; 
            }
            else if(nums[i]>max_3)
            {
                max_3 = nums[i];
            }

            if(nums[i]<min_1)
            {
                int temp1 = min_1;
                min_1 = nums[i];
                min_2 = temp1; 
            }
            else if(nums[i]<min_2)
            {
                min_2 = nums[i];
            }
        }

        return max(max_1*max_2*max_3, max_1*min_1*min_2);
        
    }
};
