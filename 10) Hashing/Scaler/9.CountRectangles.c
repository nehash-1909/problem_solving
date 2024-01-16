/*********************************************************************************************************************************
9. Count Rectangles

Given two arrays of integers A and B of size N each, where each pair (A[i], B[i]) for 0 <= i < N represents a unique point (x, y) 
in a 2-D Cartesian plane.

Find and return the number of unordered quadruplet (i, j, k, l) such that (A[i], B[i]), (A[j], B[j]), (A[k], B[k]) and (A[l], B[l]) 
form a rectangle with the rectangle having all the sides parallel to either x-axis or y-axis.
*********************************************************************************************************************************/

// SOLUTION
int Solution::solve(vector<int> &A, vector<int> &B) {
    set<pair<int,int>> map;
    int count = 0;
    for(int i=0;i<A.size();i++)
    {
        pair<int, int> temp;
        temp.first = A[i];
        temp.second = B[i];
        map.insert(temp);
    }
    for(int i=0;i<A.size();i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
            int x1 = A[i];
            int y1 = B[i];
            int x3 = A[j];
            int y3 = B[j];
            int x2 = x3; // A[j]
            int y2 = y1; // B[i]
            int x4 = x1; // A[i]
            int y4 = y3; // B[j]

            /*
                (x1,y1)    (x2 = x3,y2 = y1)
                (x4 = x1,y4 = y3)    (x3,y3)

                we have first diagonal point P1(x1,y1)
                so the second diagonal point would be one whose both x and y points are not
                same as P1.

            */
            if (A[i] != A[j] && B[i] != B[j])
            {
                if((map.find(make_pair(x2, y2))!=map.end()) && (map.find(make_pair(x4, y4))!=map.end()))
                {
                    count++;
                }
            }
        }  
    }
    
    /* We have incremented the answer twice for every rectangle 
    because every rectangle has two diagonals. */
    return count/2;
}
