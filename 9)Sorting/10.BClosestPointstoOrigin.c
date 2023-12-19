/*********************************************************************************************************************************
10. B Closest Points to Origin

We have a list A of points (x, y) on the plane. Find the B closest points to the origin (0, 0).

Here, the distance between two points on a plane is the Euclidean distance.

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in.)

NOTE: Euclidean distance between two points P1(x1, y1) and P2(x2, y2) is sqrt( (x1-x2)2 + (y1-y2)2 ).
*********************************************************************************************************************************/

// Solution

int comp(vector<int> a, vector<int> b)
{
    /*
        compare using the formula:
            sqrt( (x1-x2)2 + (y1-y2)2 )
        As we have to calculate distance from origin(0,0). So, formula becomes:
            sqrt( (x1)2 + (y1)2 )

    */
    return sqrt(a[0]*a[0] + a[1]*a[1]) < sqrt(b[0]*b[0] + b[1]*b[1]);
}
vector<vector<int> > Solution::solve(vector<vector<int> > &A, int B) {
    /*
        sort as we need B closet points from origin
    */
    sort(A.begin(),A.end(),comp);
    vector<vector<int> > res;
    for(int i=0;i<B;i++)
    {
        res.push_back(A[i]);
    }
    return res;
}
