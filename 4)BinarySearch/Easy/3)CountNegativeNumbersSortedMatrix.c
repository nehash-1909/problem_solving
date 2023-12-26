/*********************************************************************************************************************************
3. Count Negative Numbers in a Sorted Matrix

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise,
return the number of negative numbers in grid.
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
      
        int ans = 0;
        int n = grid[0].size();
        int row = grid.size()-1;
        int col = 0;

        while(row>=0 && col < n)
        {
            if(grid[row][col]<0)
            {
                ans += (n-col);
                row--;
            }
            else
            {
                col++;
            }
        }
        return ans;
    }
};
