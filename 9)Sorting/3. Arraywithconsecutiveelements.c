/*********************************************************************************************************************************
3.  Array with consecutive elements

Given an array of positive integers A, check and return whether the array elements are consecutive or not.

NOTE: Try this with O(1) extra space.
*********************************************************************************************************************************/

//Solution

int Solution::solve(vector<int> &A) {
    int min_val = INT_MAX;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]<min_val)
        {
            min_val = A[i];
        }
    }
    for(int i=0;i<A.size();i++)
    {
        A[i]=A[i]-min_val+1;
        if(A[i]>A.size())
            return 0;
    }
    for(int i=0;i<A.size();i++)
    {
        if(A[abs(A[i]) - 1] > 0)
            A[abs(A[i]) - 1] = A[abs(A[i]) - 1] * -1;
    }
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>0)
            return 0;
    }
    return 1;
}
