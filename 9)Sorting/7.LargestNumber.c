/*********************************************************************************************************************************
7. Largest Number

Given an array A of non-negative integers, arrange them such that they form the largest number.

Note: The result may be very large, so you need to return a string instead of an integer.
*********************************************************************************************************************************/

// SOlution

bool compareNum(int a, int b) {
        return to_string(a)+to_string(b) > to_string(b) + to_string(a);
    }
class Solution {
public:

    string largestNumber(vector<int>& nums) {
        string s = "";
        sort(nums.begin(),nums.end(),compareNum);
        for(int i = 0;i<nums.size();i++)
            s+=to_string(nums[i]);
        
        int i=0;
        while(s[i]=='0'&&i<s.length())
        {
            i++;
        }
        if(i==s.length())
            return "0";
        return s.substr(i);
    }
};
