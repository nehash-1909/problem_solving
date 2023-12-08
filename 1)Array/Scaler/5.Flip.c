/*********************************************************************************************************************************
5. Flip
You are given a binary string A(i.e., with characters 0 and 1) consisting of characters A1, A2, ..., AN. In a single operation, you can choose two indices, L and R, such that 1 ≤ L ≤ R ≤ N and flip the characters AL, AL+1, ..., AR. By flipping, we mean changing character 0 to 1 and vice-versa.

Your aim is to perform ATMOST one operation such that in the final string number of 1s is maximized.

If you don't want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

NOTE: Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.
*********************************************************************************************************************************/

// Solution

vector<int> Solution::flip(string A) {
    int curSum = 0;
    int sum = 0;
    vector<int> ans(2,0);
    ans[0]=-INT_MAX;
    ans[1]=-INT_MAX;
    int start = 0;
    int val;

    for(int i=0;i<A.size();i++)
    {
        // As we have to flip from l to r
        // so number of 0 in that substring should
        // be more than 1, so the we get max 1.
        if(A[i]=='0')
        {
            val = 1;
        }
        else
        {
            val = -1;
        }
        curSum += val;
        if(curSum<0)
        {
            curSum = 0;
            start = i+1;
        }
        if(curSum > sum)
        {
            sum = curSum;
            ans[1]=i+1;
            ans[0]= start+1;
        }
    }
    if(ans[1]==-INT_MAX)
    {
        return {};
    }
    return ans;
}
