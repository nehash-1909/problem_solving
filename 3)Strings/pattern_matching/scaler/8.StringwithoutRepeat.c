/*********************************************************************************************************************************
8. Longest Substring Without Repeat

Problem Description

Determine the "GOOD"ness of a given string A, where the "GOOD"ness is defined by the length of the longest substring that contains 
no repeating characters. The greater the length of this unique-character substring, the higher the "GOOD"ness of the string.

Your task is to return an integer representing the "GOOD"ness of string A.
Note: The solution should be achieved in O(N) time complexity, where N is the length of the string.
*********************************************************************************************************************************/
// Solution
int Solution::lengthOfLongestSubstring(string A) {
    unordered_set<char> st;
    int l = 0;
    int max_length = 0;

    for(int r=0;r<A.length();r++)
    {
        // Already there, so increment l till that string is removed
        if(st.find(A[r])!= st.end())
        {
            while((st.find(A[r]) !=st.end()) && (l<r))
            {
                st.erase(A[l]);
                l++;
            }
        }
        st.insert(A[r]);
        max_length = max(max_length,r-l+1);
    }
    return max_length;
}
