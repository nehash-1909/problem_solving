/*********************************************************************************************************************************
4. Another Count Rectangles

Given a sorted array of distinct integers A and an integer B, find and return how many rectangles with distinct configurations 
can be created using elements of this array as length and breadth whose area is lesser than B.
(Note that a rectangle of 2 x 3 is different from 3 x 2 if we take configuration into view)
*********************************************************************************************************************************/

// Solution

int Solution::solve(vector<int> &A, int B) {
    int l = 0;
    int r = A.size()-1;
    long mod = 1000000007;
    long count=0;
    while(l < A.size() && r >= 0)
    {
        long long area = A[l]*1l*A[r];
        if(area < B)
        {
            /*
                A = {1,2,3,4,5}
                B = 5
                if(A[l]*A[r]<B)
                means all 0 to r i.e., r+1 will give area < B,
                so add it to count
            */
            count = (count + (r+1))%mod;
            l++;
        }
        else
        {
            r--;
        }
    }
    return (int)count%mod;
}
