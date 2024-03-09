/*********************************************************************************************************************************
5.Closest Palindrome

Problem Description
Groot has a profound love for palindrome which is why he keeps fooling around with strings.
A palindrome string is one that reads the same backward as well as forward.

Given a string A of size N consisting of lowercase alphabets, he wants to know if it is possible to make 
the given string a palindrome by changing exactly one of its character.
*********************************************************************************************************************************/
// Solution

string Solution::solve(string A) {
    int count = 0;
    int l =0;
    int r =  A.length()-1;
    while(l<r)
    {
        if(A[l] != A[r])
            count++;
        l++;
        r--;
    }
    if(count == 1)
    {
        return "YES";
    }
    if(count == 0)
    {
        if(A.length()%2 == 1)
        {
            return "YES";
        }
        return "NO";
    }
    return "NO";
}
