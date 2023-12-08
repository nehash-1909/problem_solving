/*********************************************************************************************************************************
6. Equilibrium index of an array
You are given an array A of integers of size N.

Your task is to find the equilibrium index of the given array

The equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes.

If there are no elements that are at lower indexes or at higher indexes, then the corresponding sum of elements is considered as 0.
*********************************************************************************************************************************/

// Solution

int Solution::solve(vector<int> &A) {
    vector<int> prefix(A.size(),0);
    vector<int> suffix(A.size(),0);
    prefix[0] = A[0];
    for(int i=1;i<A.size();i++)
    {
        prefix[i] = prefix[i-1] + A[i];
    }

    suffix[A.size()-1] = A[A.size()-1];
    for(int i=A.size()-2;i>=0;i--)
    {
        suffix[i] = suffix[i+1] + A[i];
    }

    for(int i=0;i<A.size();i++)
    {
        if(prefix[i] == suffix[i])
        {
            return i;
        }
    }

    return -1;

}
