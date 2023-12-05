/*********************************************************************************************************************************
3. Subarray Sum Equals K

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> map;

        int sum = 0;    

        int ans = 0;

        // 1 2 3, k =3, m[1] = 1, ans =1
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            if(sum == k)
            {
                ans++;
            }
            if(map.find(sum-k)!=map.end())
            {
                ans += map[sum-k];
            }

            map[sum]++;
        }

        return ans;

        
        
    }
};

