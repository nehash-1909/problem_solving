/*********************************************************************************************************************************
3. Find the Index of the First Occurrence in a String

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    int strStr(string haystack, string needle) {
        int j = 0;

        for(int i=0;i<haystack.length();i++)
        {
            for(j=0;j<needle.length();j++)
            {
                if(haystack[i+j] != needle[j])
                {
                    break;
                }
            }
            if(j==needle.length())
                return i;
        }
        return -1;
    }
};
