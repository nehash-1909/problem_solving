/*********************************************************************************************************************************
2. RProduct of Array Except Self

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*********************************************************************************************************************************/

//Solution

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size() - 1;
        vector<int> prefix(n+1);
        vector<int> suffix(n+1);
        prefix[0] = 1;
        suffix[n] = 1;

        for(int i=1;i<=n;i++)
        {
            prefix[i] = prefix[i-1]*nums[i-1];
        }

        for(int i=n-1;i>=0;i--)
        {
            suffix[i] = suffix[i+1]*nums[i+1];
        }

        vector<int> ans(n+1);

        for(int i=0;i<=n;i++)
        {
            int temp = (prefix[i]*suffix[i]);
            ans[i] = temp;
        }


        return ans;
        
    }
};
