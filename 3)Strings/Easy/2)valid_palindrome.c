/*********************************************************************************************************************************
2. Valid Palindrome II

Given a string s, return true if the s can be palindrome after deleting at most one character from it.
*********************************************************************************************************************************/

//Solution

class Solution {
public:
    bool checkPalindrome(string s, int left, int right) {
        while(left<right)
        {
            if(s[left]!=s[right])
            {
                return 0;
            }
            left++;
            right--;
        }
        return 1;
    }
    bool validPalindrome(string s) {
        int count = 0;
        int left_p = 0;
        int right_p = s.length()-1;
        while(left_p<right_p)
        {
            if(s[left_p]!=s[right_p])
            {
                
                return checkPalindrome(s, left_p+1, right_p) || checkPalindrome(s, left_p, right_p-1);
            }
            else
            {
                left_p++;
                right_p--;
            }
        }
        return 1;
    }
};
