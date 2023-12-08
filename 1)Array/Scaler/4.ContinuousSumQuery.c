/*********************************************************************************************************************************
4. Continuous Sum Query
There are A beggars sitting in a row outside a temple. Each beggar initially has an empty pot. When the devotees come to the temple, they donate some amount of coins to these beggars. Each devotee gives a fixed amount of coin(according to their faith and ability) to some K beggars sitting next to each other.

Given the amount P donated by each devotee to the beggars ranging from L to R index, where 1 <= L <= R <= A, find out the final amount of money in each beggar's pot at the end of the day, provided they don't fill their pots by any other means.
For ith devotee B[i][0] = L, B[i][1] = R, B[i][2] = P, given by the 2D array B
*********************************************************************************************************************************/

// Solution

vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> begger(A,0);
    vector<int> ans(A,0);
  
    for(int i = 0;i< B.size();i++)
    {
        // Add coins for first begger
        begger[B[i][0]-1] += B[i][2];
        if(B[i][1]<A)
        {
            // The last begger was at index B[i][1]-1
            // while calculating prefix array we want
            // to stop index at B[i][1];
            begger[B[i][1]] -= B[i][2];
        }
    }
    ans[0] = begger[0];
    for(int i = 1;i< A;i++)
    {
        // Calculate coins from start to end index;
        ans[i] = ans[i-1] + begger[i];
    }
    return ans;
}
