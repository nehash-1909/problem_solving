/*********************************************************************************************************************************
16. Subarray Sums Divisible by K

Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int curSum = 0;
        map<int,int> map;
        int ans = 0;
        map[0] = 1;
        for(int i=0;i<nums.size();i++)
        {
            curSum += nums[i];

            int rem = curSum%k;

            if(rem<0)
            {
                rem += k;
            }
            if(map.find(rem)!=map.end())
            {
                ans += (map[rem]);
            }

                map[rem]++;
            
        }
        return ans;
    }
        
};
