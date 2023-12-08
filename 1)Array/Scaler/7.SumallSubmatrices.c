/*********************************************************************************************************************************
7. Sum of all Submatrices

Given a 2D Matrix A of dimensions N*N, we need to return the sum of all possible submatrices.
*********************************************************************************************************************************/

// Solution
int Solution::solve(vector<vector<int> > &A) {
    //[[1,1],[1,2], [1,3],]
    int sum = 0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
            // every A[i][j] can have top corner from 0,0, i+1,j+1
            // and bottom from it can be from n-i, n-j to n,n
            sum += A[i][j]*(i+1)*(j+1)*(A.size()-i)*(A.size()-j);
        }

    }
    return sum;
}
