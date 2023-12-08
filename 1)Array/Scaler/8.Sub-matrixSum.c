/*********************************************************************************************************************************
8. Sub-matrix Sum Queries

Given a matrix of integers A of size N x M and multiple queries Q, for each query, find and return the submatrix sum.

Inputs to queries are top left (b, c) and bottom right (d, e) indexes of submatrix whose sum is to find out.
*********************************************************************************************************************************/

// Solution

vector<int> Solution::solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {
    int row = A.size();
    int col = A[0].size();
    
    vector<vector<int>> prefix( row , vector<int> (col, 0));
    vector<vector<int>> colSum( row , vector<int> (col, 0));
    vector<int> ans(B.size(),0);

    for(int i=0;i<col;i++)
    {
        prefix[0][i] = A[0][i];
    }

    for(int i=1;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            long long sum;
            sum = prefix[i-1][j] + A[i][j];

            prefix[i][j] = sum%1000000007;
        }
        
    }

    for(int i=0;i<row;i++)
    {
        colSum[i][0]=prefix[i][0];
        for(int j=1;j<col;j++)
        {
            long long sum;
            sum = colSum[i][j-1] + prefix[i][j];

            colSum[i][j] = sum%1000000007;
        }
    }

    for(int i=0;i<B.size();i++)
    {
        long long sum = 0;
        sum = colSum[D[i]-1][E[i]-1];
        if(B[i]>1)
        {
            sum -=colSum[B[i]-2][E[i]-1];
        }
        if(C[i]>1)
        {
            sum -=colSum[D[i]-1][C[i]-2];
        }
        if(B[i]>1 && C[i]>1)
        {
            sum = (sum%1000000007 + colSum[B[i]-2][C[i]-2]%1000000007)%1000000007;
            
        }
        while (sum < 0)
            sum += 1000000007;

        ans[i] = sum;
    }
    return ans;
}
