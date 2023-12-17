/*********************************************************************************************************************************
1. Merge Two Sorted Arrays

Given two sorted integer arrays A and B, merge B and A as one sorted array and return it as an output.

Note: A linear time complexity is expected and you should avoid use of any library function.
*********************************************************************************************************************************/

// Solution

vector<int> Solution::solve(const vector<int> &A, const vector<int> &B) {
    int i1=0;
    int i2=0;
    vector<int> res;
    while(i1<A.size() && i2<B.size())
    {
        if(A[i1]<B[i2])
        {
            res.push_back(A[i1]);
            i1++;
        }
        else
        {
            res.push_back(B[i2]);
            i2++;
        }
    }
    while(i1<A.size())
    {
        res.push_back(A[i1]);
        i1++;
    }
    while(i2<B.size())
    {
        res.push_back(B[i2]);
        i2++;
    }
    return res;
}
