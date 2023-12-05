/*********************************************************************************************************************************
1. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());
 
        for(int i=0; i<nums.size()-2;i++)
        {
            int l = i+1;
            int r = nums.size()-1;
            int temp = nums[i];
            while(l<r)
            {

                if(temp+nums[l]+nums[r]==0)
                {
                    s.insert({nums[l],nums[r],temp});
                    l++;
                    r--;
                }
                else if((temp+nums[l]+nums[r])  < 0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }

        for(auto i:s)
        {
            ans.push_back(i);
        }

        return ans;
    }
};
