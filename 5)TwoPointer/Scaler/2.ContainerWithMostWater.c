/*********************************************************************************************************************************
2. Container With Most Water

Given N non-negative integers A[0], A[1], ..., A[N-1] , where each represents a point at coordinate (i, A[i]).

N vertical lines are drawn such that the two endpoints of line i is at (i, A[i]) and (i, 0).

Find two lines, which together with x-axis forms a container, such that the container contains the most water. You need to return this maximum area.

Note: You may not slant the container. It is guaranteed that the answer will fit in integer limits.
*********************************************************************************************************************************/

//Solution

int Solution::maxArea(vector<int> &A) {
    /*
        __
       |  |__
       |  |  |__
       |  |  |  |
     __|  |  |  |
    |  |  |  |  |

      1  5  4   3
    
    Max Area : (j-i)*min(A[j],A[i])
    */
    int l = 0;
    int r = A.size()-1;
    int ans = 0;
    while(l<r)
    {
        int min_val = min(A[r],A[l]);
        ans = max(ans, (r-l)*min_val);
        if(A[r]<A[l])
        {
            r--;
        }
        else
        {
            l++;
        }   
    }
    return ans;
}
