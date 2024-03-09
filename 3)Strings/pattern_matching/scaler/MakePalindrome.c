/*********************************************************************************************************************************
4. Make String Palindrome

Problem Description
Given a string A of size N consisting only of lowercase alphabets. The only operation allowed is to insert characters in the 
beginning of the string.

Find and return how many minimum characters are needed to be inserted to make the string a palindrome string.
*********************************************************************************************************************************/
// Solution

vector<int> build_lps(string s)
{
    int n= s.length();
    vector<int> lps(n,0);
    lps[0] = 0;
    for(int i=1;i<n;i++)
    {
        int x = lps[i-1];
        while(s[x] != s[i])
        {
            if(x == 0)
            {
                x = -1;
                break;
            }
            x = lps[x-1];
        }
        lps[i] = x+1;
    }
    return lps;
}
int Solution::solve(string A) {
    string rev = string(A.rbegin(), A.rend());
    string s = A + '@' + rev;
    vector<int> lps = build_lps(s);
    if(lps[s.length()-1] == A.length())
        return 0;
    return A.length()-lps[s.length()-1];
}

