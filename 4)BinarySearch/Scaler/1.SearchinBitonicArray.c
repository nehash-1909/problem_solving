/*********************************************************************************************************************************
1.Search in Bitonic Array!

Problem Description

Given a bitonic sequence A of N distinct elements, write a program to find a given element B in the bitonic sequence in O(logN) time.

NOTE: A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.
*********************************************************************************************************************************/
// Solution

int leftSearch(vector<int> &A,int idx, int B) {
    int l = 0;
    int r = idx;

    while(l<=r)
    {
        int m = (l+r)/2;
        if(A[m]==B)
        {
            return m;
        }
        else if(A[m]>B)
        {
            r = m-1;
        }
        else
        {
            l = m+1;
        }
    }
    return -1;
}
int rightSearch(vector<int> &A,int idx,int B) {
    int l = idx;
    int r = A.size()-1;

    while(l<=r)
    {
        int m = (l+r)/2;
        if(A[m]==B)
        {
            return m;
        }
        else if(A[m]>B)
        {
            l = m+1;
        }
        else
        {
            r = m-1;
        }
    }
    return -1;
}
int getPivot(vector<int> &A)
{
    int l = 0;
    int r = A.size()-1;
    int n = A.size()-1;
    while(l<=r)
    {
        int m = (l+r)/2;
        if(((m==0)||(A[m]>A[m-1]))&&((m==n)||(A[m]>A[m+1])))
        {
            return m;
        }
        else if(A[m]>A[m+1])
        {
            // right side
            r = m-1;
        }
        else
        {
            l = m+1;
        }    
    }
    return -1;
}
int Solution::solve(vector<int> &A, int B) {
    int idx = getPivot(A);
    if(A[idx]==B)
    {
        return idx;
    }
    int left = leftSearch(A,idx-1,B);
    if(left!=-1)
    {
        return left;
    }
    return rightSearch(A,idx+1,B);    
}
