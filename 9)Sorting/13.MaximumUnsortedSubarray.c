/*********************************************************************************************************************************
13.Maximum Unsorted Subarray

Given an array A of non-negative integers of size N. Find the minimum sub-array Al, Al+1 ,..., Ar 
such that if we sort(in ascending order) that sub-array, then the whole array should get sorted. If A is already sorted, output -1.
*********************************************************************************************************************************/

// Solution
vector<int> Solution::subUnsort(vector<int> &A) {
    /*
    Assume that Al, …, Ar is the minimum-unsorted-subarray which is to be sorted.
    then min(Al, …, Ar) >= max(A0, …, Al-1)
    and max(Al, …, Ar) <= min(Ar+1, …, AN-1)
    */
    vector<int> result;
    int l, r,minVal,maxVal;
    int n = A.size();
    for(int i=0;i<n-1;i++)
    {
        if(A[i]>A[i+1])
        {
            l = i;
            break;
        }
    }
    if(l==n-1)
    {
        result.push_back(-1);
        return result;
    }
    for(int i=n-1;i>=1;i--)
    {
        if(A[i]<A[i-1])
        {
            r = i;
            break;
        }
    }
    minVal = A[l];
    maxVal = A[l];
    for(int i=l;i<=r;i++)
    {
        minVal = min(minVal,A[i]);
        maxVal = max(maxVal,A[i]);
    }

    for(int i=0;i<=l;i++)
    {
        if(A[i]>minVal)
        {
            result.push_back(i);
            break;
        }
    }

    for(int i=n-1;i>=r;i--)
    {
        if(A[i]<maxVal)
        {
            result.push_back(i);
            break;
        }
    }
    return result;

}
