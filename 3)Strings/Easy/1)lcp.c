/*********************************************************************************************************************************
1. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

*********************************************************************************************************************************/


// Solution

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int max_len = 201;
        string res = "";
        for(auto i: strs)
        {
            if(i.length()<max_len)
            {
                max_len = i.length();
            }
        }
        for(int i=0;i<max_len;i++)
        {
            char ltr = strs[0][i];
            for(int j=1;j<strs.size();j++)
            {
                if(strs[j][i]!=ltr)
                {
                    return res;
                }                
            }
            res += ltr;
        }
        return res;
    }
};
