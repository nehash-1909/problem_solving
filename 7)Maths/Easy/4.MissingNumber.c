/*********************************************************************************************************************************
4. Missing Number
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
*********************************************************************************************************************************/

//Solution
class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int a = nums[0];
        int b = 1;

        for(int i=1;i<nums.size();i++)
        {
            a ^= nums[i];
        }

        for(int i=2;i<nums.size()+1;i++)
        {
            b ^= i;
        }

        return a^b;
    }
};
