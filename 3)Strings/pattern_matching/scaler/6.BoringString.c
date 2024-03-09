/*********************************************************************************************************************************
6.Boring substring
Problem Description

You are given a string A of lowercase English alphabets. Rearrange the characters of the given string A such that there 
is no boring substring in A.
A boring substring has the following properties:
  i) Its length is 2.
 ii) Both the characters are consecutive, 

for example - "ab", "cd", "dc", "zy" etc.(If the first character is C then the next character can be either (C+1) or (C-1)).
Return 1 if it is possible to rearrange the letters of A such that there are no boring substrings in A else, return 0.
*********************************************************************************************************************************/
// Solution
int Solution::solve(string A) {
    string odd = "";
    string even = "";
    // All odd parity needs to stay together. Similarly, all even parity characters need to stay together.
    for(int i=0;i<A.length();i++)
    {
        if(A[i]%2==0)
        {
            even += A[i];
        }
        else
        {
            odd += A[i];
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    if(abs(odd[odd.length()-1]-even[0]) != 1)
    {
        return 1;
    }
    if(abs(even[even.length()-1]-odd[0]) !=1)
    {
        return 1;
    }
    return 0;
}
