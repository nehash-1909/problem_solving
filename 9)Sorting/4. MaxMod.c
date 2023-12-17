/*********************************************************************************************************************************
4. MaxMod

Given an array A of size N, Groot wants you to pick 2 indices i and j such that 1 <= i, j <= N
A[i] % A[j] is maximum among all possible pairs of (i, j).
Help Groot in finding the maximum value of A[i] % A[j] for some i, j.
*********************************************************************************************************************************/

// Solution

int Solution::solve(vector<int> &A)
{

    /*
         maximum value of A[i] % A[j], A[i]<A[j]
         can be max when A[j] is maximum, now
         now for A[i] it should be second max to be max result.
    */

    int maxVal    = INT_MIN; 
    int maxsecVal = INT_MIN;

    for(int i=0;i<A.size();i++)
    {
        if(A[i]>maxVal)
        {
            maxsecVal = maxVal;
            maxVal = A[i];
        }
        else if(A[i]>maxsecVal && A[i]!=maxVal)
        {
            maxsecVal = A[i];
        }
    }
    if(maxVal==INT_MIN || maxsecVal==INT_MIN)
        return 0;
    return maxsecVal%maxVal;

}
