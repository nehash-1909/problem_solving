/*********************************************************************************************************************************
6. Search in a 2D Matrix Optimal

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*********************************************************************************************************************************/
// Solution

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
            flatten 2d matrix to 1 d then elements will be sorted,
            then this problem will become normal binary search.
            matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
            row = 0 : n
            col = 0 : m
            after flattening:
            matrix = [1,3,5,7,10,11,16,20,23,30,34,60]
            i : 0 to n*m
            row = i%col
            col = i/col

        */
        int row = matrix.size();
        int col = matrix[0].size();
        int l = 0;
        int r = row*col-1;
        while(l<=r)
        {
            int m = (l+r)/2;
            int onedRow = m/col;
            int onedCol = m%col;
            if(matrix[onedRow][onedCol] == target)
            {
                return true;
            }
            else if(matrix[onedRow][onedCol] > target)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return false;
    }
};
