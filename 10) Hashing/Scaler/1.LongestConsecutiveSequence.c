/*********************************************************************************************************************************
1. Longest Consecutive Sequence

Given an unsorted integer array A of size N.

Find the length of the longest set of consecutive elements from array A.
*********************************************************************************************************************************/

// Solution

int Solution::longestConsecutive(const vector<int> &A) {
    set<int> s;
    int count = 1;
    int ans = 1;
    for(int i=0;i<A.size();i++)
    {
        s.insert(A[i]);
    }
    set<int>:: iterator it;
    for(int i=0;i<A.size();i++)
    {
        count = A[i];
        // if previous element already handled by else case
        if (s.find(A[i] - 1) != s.end()) {
            continue;
        }
        while (s.find(count) != s.end())
        {
            count++;
        }
        ans = max(ans,count-A[i]);
    }
    return ans;
}


