/*********************************************************************************************************************************
8. Check Palindrome - II
Given a string A consisting of lowercase characters.
Check if characters of the given string can be rearranged to form a palindrome.
Return 1 if it is possible to rearrange the characters of the string A such that it becomes a palindrome else return 0.
*********************************************************************************************************************************/
// Solution

int Solution::solve(string A) {
    unordered_map<int,int> map;
    int count = 0;
    for(int i=0;i<A.size();i++)
    {
        map[A[i]]++;
    }
    for(auto i:map)
    {
        if(i.second%2 == 1)
        {
            if(count==1)
            {
                return false;
            }
            else
            {
                count++;
            }
        }
    }
    return true;
}
