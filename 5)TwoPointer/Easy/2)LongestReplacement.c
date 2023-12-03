/*********************************************************************************************************************************
2. Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> map;
        int l = 0;
        int r = 0;
        int max_freq = 0;
        int res = 0;
        for(r=0;r<s.length();r++)
        {
            map[s[r]]++;
            max_freq = max(max_freq, map[s[r]]);

            if((r-l+1)-max_freq > k)
            {
                map[s[l]]--;
                l++;
            }
            else
            {
                res = max(res, r-l+1);
            }
        }
        return res;
        
    }
};
