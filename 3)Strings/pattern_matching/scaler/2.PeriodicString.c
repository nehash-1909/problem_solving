/*********************************************************************************************************************************
2. Period of a string
Problem Description

You are given a string A of length N consisting of lowercase alphabets. Find the period of the string.
Period of the string is the minimum value of k (k >= 1), that satisfies A[i] = A[i % k] for all valid i.
*********************************************************************************************************************************/
// Solution
vector<int> build_lps(string s)
{
    int n = s.length();
    vector<int> lps(n,0);
    lps[0] = 0;
    for(int i=1;i<n;i++)
    {
        int x = lps[i-1];
        while(s[x] != s[i])
        {
            if(x==0)
            {
                x =-1;
                break;
            }
            x = lps[x-1];
        }
        lps[i] = x+1;
    }
    return lps;
}
int Solution::solve(string A) {
    vector<int> lps = build_lps(A);
    return A.length()-lps[A.length()-1];
}
