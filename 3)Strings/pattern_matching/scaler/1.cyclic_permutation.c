/*********************************************************************************************************************************
1. Cyclic Permutations

Given two binary strings A and B, count how many cyclic shift of B when taken XOR with A give 0.

NOTE: If there is a string, S0, S1, ... Sn-1 , then it is a cyclic shift is of the form Sk, Sk+1, ... Sn-1, S0, S1, ... Sk-1 
where k can be any integer from 0 to N-1.
*********************************************************************************************************************************/
// Solution

vector<int> buildLPS(string str)
{
    vector<int> lps(str.length(),0);
    lps[0] = 0;
    int x;
    for(int i=1;i<str.length();i++)
    {
        int x = lps[i-1];
        while(str[x] != str[i])
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

int Solution::solve(string A, string B) {
    string str = A + '$' + B + B.substr(0, B.size() - 1);
    vector<int> lps = buildLPS(str);
    int count = 0;
    for(int i=0;i<str.length();i++)
    {
        if(lps[i] == A.length())
        {
            count++;
        }
    }
    return count;
}
