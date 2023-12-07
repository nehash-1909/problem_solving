/*********************************************************************************************************************************
1. First Missing Integer

Given an unsorted integer array, A of size N. Find the first missing positive integer.

Note: Your algorithm should run in O(n) time and use constant space.
*********************************************************************************************************************************/

// Solution

int Solution::firstMissingPositive(vector<int> &A) {

    int n = A.size();
    for(int i=0;i<A.size();i++)
    {
        while(A[i]>=1 && A[i]<=n && A[i] != A[A[i] - 1])
        {
            swap(A[i],A[A[i]-1]);
        }
    }

    for(int i=0;i<A.size();i++)
    {
        if(A[i]!=i+1)
        {
            return i+1;
        }   
    }

}


