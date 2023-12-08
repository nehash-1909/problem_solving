/*********************************************************************************************************************************
11. Spiral Order Matrix II

Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order and return the generated square matrix.
*********************************************************************************************************************************/

// Solutiom

vector<vector<int> > Solution::generateMatrix(int A) {
    int indx = 1;
    int top = 0;
    int bottom = A-1;
    int left = 0;
    int right = A-1;
    vector<vector<int> > ans(A, vector<int>(A,0));

    while(left<=right && top<=bottom)
    {
         if(top <= bottom)
        {
            for(int i= left ;i<= right;i++)
            {
                ans[top][i] = indx;
                indx++;
                
            }
            top++;
        }
        if(left <= right)
        {
            for(int i= top ;i<= bottom;i++)
            {
                ans[i][right] = indx;
                indx++;
                
            }
            right--;
        }   
        if(top <= bottom)
        {
            for(int i= right ;i>= left;i--)
            {
                ans[bottom][i] = indx;
                indx++;
                
            }
            bottom--;
        }
        if(left <= right)
        {
            for(int i= bottom ;i>= top;i--)
            {
                ans[i][left] = indx;
                indx++;
                
            }
            left++;
        }
    }
    return ans;
}

