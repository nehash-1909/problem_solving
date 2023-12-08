/*********************************************************************************************************************************
3. Max Non Negative SubArray
Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array.

Find and return the required subarray.
*********************************************************************************************************************************/

// Solution

vector<int> Solution::maxset(vector<int> &A) {

    long long sum = -INT_MAX ;
    long long curSum = 0;
    vector<int> ans;

    for(int i=0;i<A.size();i++)
    {
        int s = i;
        int e = i;
        while(i<A.size()&&A[i]>=0)
        {
            curSum += A[i];
            i++;
        }
        e = i-1;
        if(curSum > sum)
        {
            ans.clear();   
            sum = curSum;
            for(int j=s;j<=e;j++)
            {
                ans.push_back(A[j]);
            }
        }
        curSum = 0;
    }
    return ans;
}
