/*********************************************************************************************************************************
11. Replicating Substring

Given a string B, find if it is possible to re-order the characters of the string B so that it can be represented as a 
concatenation of A similar strings.

Eg: B = aabb and A = 2, then it is possible to re-arrange the string as "abab" which is a concatenation of 2 similar strings "ab".

If it is possible, return 1, else return -1.
*********************************************************************************************************************************/

// Solution

int Solution::solve(int A, string B) {
    int map[26];
    memset(map, 0, sizeof(map));
    for(int i=0;i<B.size();i++)
    {
        map[B[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(((map[i])%A)!=0)
        {
            return -1;
        }
    }
    return 1;
}

