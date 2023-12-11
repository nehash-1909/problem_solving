/*********************************************************************************************************************************
3. Excel Sheet Column Title

Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber)
        {
            int remainder = (columnNumber - 1)%26;
            ans += 'A' + remainder;
            columnNumber = (columnNumber-1)/26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
