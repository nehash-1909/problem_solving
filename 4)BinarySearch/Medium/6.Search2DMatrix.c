/*********************************************************************************************************************************
6. Search in a 2D Matrix

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*********************************************************************************************************************************/
// Solution

  class Solution {
public:
    int findRow(vector<vector<int>>& matrix,int row,int col, int target) 
    {
        int l =0;
        int r = row;
        int ans = -1;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(matrix[m][col]>=target)
            {
                ans = m;
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        return ans;
    }

    int findCol(vector<vector<int>>& matrix,int row,int col, int target) 
    {
        int l =0;
        int r = col;
        int ans = -1;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(matrix[row][m]>=target)
            {
                ans = m;
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        return ans;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1;
        int col = matrix[0].size()-1;
        int indxRow = findRow(matrix,row,col,target);
        if(indxRow == -1)
        {
            return false;
        }
        if(matrix[indxRow][col] == target)
        {
            return true;
        }
        int indxCol = findCol(matrix,indxRow,col,target);
        if(indxCol == -1)
        {
            return false;
        }
        if(matrix[indxRow][indxCol] == target)
        {
            return true;
        }
        return false;
    }
};
