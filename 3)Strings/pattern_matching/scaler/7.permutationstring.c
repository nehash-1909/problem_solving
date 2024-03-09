/*********************************************************************************************************************************
7. Permutations of A in B

Problem Description

You are given two strings, A and B, of size N and M, respectively.

You have to find the count of all permutations of A present in B as a substring. You can assume a string will have only lowercase letters.
*********************************************************************************************************************************/
// Solution
bool check_pre(int* hashmap, int* hashmapB)
{
    for(int i=0;i<26;i++)
    {
        if(hashmap[i] != hashmapB[i])
        {
            return false;
        }
    }
    return true;
}
int Solution::solve(string A, string B) {
    int n = A.length();
    int m = B.length();
    int count = 0;
    int hashmap[26], hashmapB[26];
    // Reset hash maps
    for (int i = 0; i < 26; i += 1) {
        hashmap[i] = hashmapB[i] = 0;
    }
    for(auto i:A)
    {
        hashmap[i-'a']++;
    }
    for(int j=0;j<A.length();j++)
    {
        hashmapB[B[j]-'a']++;
    }
    if(check_pre(hashmap,hashmapB)==true)
    {
        count++;
    }
    for(int j=n;j<m;j++)
    {
        hashmapB[B[j-n]-'a']--;
        hashmapB[B[j]-'a']++;
        if(check_pre(hashmap,hashmapB)==true)
        {
            count++;
        }
    }
    return count;
}

