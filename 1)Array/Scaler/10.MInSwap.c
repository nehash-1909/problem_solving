/*********************************************************************************************************************************
10. Min Swap

Given an array of integers A and an integer B, find and return the minimum number of swaps required to bring all the numbers less than or equal to B together.

Note: It is possible to swap any two elements, not necessarily consecutive.
*********************************************************************************************************************************/

// Solution

int Solution::solve(vector<int> &A, int B) {
    int max_swap = 0;
    int ans = INT_MAX;
    int bad_num_window = 0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]<=B)
        {
            max_swap++;
        }
    }
    if(max_swap<=1)
    {
        return 0;
    }
    int l = 0;
    int r = max_swap;
    for(int i=l;i<r;i++)
    {
        if(A[i]>B)
        {
            bad_num_window++;
        }
    }
    ans = min(ans,bad_num_window);
    while(r<A.size())
    {
        if(A[l]>B)
        {
            bad_num_window--;
        }
        if(A[r]>B)
        {
            bad_num_window++;
        } 
        ans = min(ans,bad_num_window);  
        l++;
        r++;    
    }
    return ans;
}
