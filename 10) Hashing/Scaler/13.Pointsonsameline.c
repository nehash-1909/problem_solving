/*********************************************************************************************************************************
13. Points on same line

Given two arrays of integers A and B describing a pair of (A[i], B[i]) coordinates in a 2D plane. 
A[i] describe x coordinates of the ith point in the 2D plane, whereas B[i] describes the y-coordinate of the ith point in the 2D plane.

Find and return the maximum number of points that lie on the same line.
*********************************************************************************************************************************/

// Solution
int Solution::solve(vector<int> &A, vector<int> &B) {
    
    double slope;
    int ans = 0;
    for(int i=0;i<A.size();i++)
    {
        pair<int,int> p1;
        p1.first = A[i];
        p1.second = B[i];
        map<double, int> map;
        int same = 0;
        for(int j=i+1;j<A.size();j++)
        {
            pair<int,int> p2;
            p2.first = A[j];
            p2.second = B[j];

            /* checking for equal points */
			      if (p1.first == p2.first && p1.second == p2.second)
			      {
				        same++;
			      }
            else if(p2.first == p1.first)
            {
                /* for slope infinite  */
                slope = (double)INT_MAX;
            }
            else
            {
                slope = ((double)p2.second - (double)p1.second)/((double)p2.first - (double)p1.first);
            }
            map[slope]++;
            ans = max(ans,map[slope]+1+same);
        }
    }
    return ans;
}
