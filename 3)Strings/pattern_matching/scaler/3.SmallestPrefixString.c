/*********************************************************************************************************************************
3.Smallest Prefix String
Problem Description

Given 2 strings A and B of size N and M respectively consisting of lowercase alphabets, 
find the lexicographically smallest string that can be formed by concatenating non-empty prefixes of A and B (in that order).
Note: The answer string has to start with a non-empty prefix of string A followed by a non-empty prefix of string B.
*********************************************************************************************************************************/
// Solution

string Solution::smallestPrefix(string A, string B) {
    int i=0;
    string ans;
    for(i=1;i<A.length();i++)
    {
        if(A[i]>=B[0])
        {
            break;
        }
    }
    if(i==0)
    {
        ans = A[0]+B[0];
        return ans;
    }
    ans = A.substr(0, i)+B[0];
    return ans;
}
