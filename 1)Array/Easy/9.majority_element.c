/*********************************************************************************************************************************
9. Majority Element

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int selected_ele = 0, votes = 0;
        for(auto i : nums)
        {
            if(votes == 0)
            {
                selected_ele = i;
            }
            if( selected_ele == i )
            {
                votes++;
            }
            else
            {
                votes--;
            }
        }
        return selected_ele;
        
    }
};
