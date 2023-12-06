/*********************************************************************************************************************************
6. Sprial Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0;
        int right = m-1;
        int top = 0;
        int bottom = n-1;
        while(left<=right && top<=bottom)
        {
            // left -->right

            if(top <= bottom)
            {
                for(int i=left;i<=right;i++)
                {
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
            //top-->bottom
            if(left <= right)
            {
                for(int i=top;i<=bottom;i++)
                {
                    res.push_back(matrix[i][right]);   
                }
                right--;
            }

            if(top <= bottom)
            {
            //right-->left
                for(int i=right;i>=left;i--)
                {
                    res.push_back(matrix[bottom][i]);   
                }
                bottom--;
            }
            //bottom-->up
            if(left <= right)
            {
                for(int i=bottom;i>=top;i--)
                {
                    res.push_back(matrix[i][left]);  
                }
                left++;
            }
        }

        return res;
        
    }
};
