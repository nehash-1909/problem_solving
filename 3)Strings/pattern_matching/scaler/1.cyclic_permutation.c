/*********************************************************************************************************************************
1. Cyclic Permutations

Given two binary strings A and B, count how many cyclic shift of B when taken XOR with A give 0.

NOTE: If there is a string, S0, S1, ... Sn-1 , then it is a cyclic shift is of the form Sk, Sk+1, ... Sn-1, S0, S1, ... Sk-1 
where k can be any integer from 0 to N-1.
*********************************************************************************************************************************/
// Solution

vector<int> lps(string s)
{
    int n = s.length();
    vector<int> lps_array(n,0);
    lps_array[0] = 0;
    for(int i =1;i<n;i++)
    {
        int x = lps_array[i-1];
        while(s[x] != s[i])
        {
            if(x == 0)
            {
                x = -1;
                break;
            }
            x = lps_array[x-1];
        }
        lps_array[i] = x+1;
    }
    return lps_array;
}
int Solution::solve(string A, string B) {
    int counter = 0;
    string x = A + '$' + B + B.substr(0, B.size() - 1); // so that it doesn't count intial string twice
    vector<int> lps_array = lps(x);
    for(int i=A.length()+1;i<x.length();i++)
    {
        if(lps_array[i] == A.length())
        {
            counter++;
        }
    }
    return counter;
}
