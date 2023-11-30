/*********************************************************************************************************************************
7. Squares of a Sorted Array

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        int left_pointer = 0;
        int right_pointer = nums.size()-1;
        while(left_pointer <= right_pointer)
        {
            if(abs(nums[left_pointer])>abs(nums[right_pointer]))
            {
                result.push_back(nums[left_pointer]*nums[left_pointer]);
                left_pointer++;
            }
            else
            {
                result.push_back(nums[right_pointer]*nums[right_pointer]);
                right_pointer--;
                
            }
        }
        reverse(result.begin(),result.end());
        return result;
        
    }
};
