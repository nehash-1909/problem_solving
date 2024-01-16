/*********************************************************************************************************************************
10. Count Right Triangles

Given two arrays of integers A and B of size N each, where each pair (A[i], B[i]) for 0 <= i < N represents a unique point 
(x, y) in 2D Cartesian plane.

Find and return the number of unordered triplets (i, j, k) such that (A[i], B[i]), (A[j], B[j]) and (A[k], B[k]) form a 
right-angled triangle with the triangle having one side parallel to the x-axis and one side parallel to the y-axis.

NOTE: The answer may be large so return the answer modulo (109 + 7).
*********************************************************************************************************************************/

// Solution

int Solution::solve(vector<int> &A, vector<int> &B) {

    unordered_map<int,int> x;
    unordered_map<int,int> y;
    int count = 0;
    const int mod = 1e9+7 ;
    for(int i=0;i<A.size();i++)
    {
        x[A[i]]++;
        y[B[i]]++;
    }
    /*
        (x2,y1)
        (x1,y1)   (x3,y1)
    */

    for(int i=0;i<A.size();i++)
    {
        // one is substracted because one of the points would same
        count = count%mod + (((x[A[i]]-1)%mod)*((y[B[i]]-1)%mod))%mod;
    }
    return count;
}
