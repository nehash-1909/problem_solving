/*********************************************************************************************************************************
8. Special Integer

Problem Description

Given an array of integers A and an integer B,
find and return the maximum value K such that there is no subarray in A of size K with the sum of elements greater than B.
*********************************************************************************************************************************/
// Solution

bool ifpossible(vector<int> &A, int B, int k)
{
    long sum = 0;
    for(int i=0;i<k;i++)
    {
        sum+=A[i];
    }
    if(sum>B)
        return false;

    for(int i=k;i<A.size();i++)
    {
        sum-=A[i-k];
        sum+=A[i];
        if(sum>B)
            return false;
    }
    return true;
}
int Solution::solve(vector<int> &A, int B) {
    int l = 0;
    int r = A.size();
    int ans=-1;
    int m;
    while(l<=r)
    {
        m = (r-l)/2+l;
        //cout<<"m is "<<m<<" l is "<<l<<"r is "<<r<<endl;

        if(ifpossible(A,B,m))
        {
            ans = m;
            l = m+1;
        }
        else{
            r = m-1;
        }

    }
    return ans;
}

