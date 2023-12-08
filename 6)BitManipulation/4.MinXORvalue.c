/*********************************************************************************************************************************
4. Min XOR value

Given an integer array A of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.
*********************************************************************************************************************************/

// Solution

int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(),A.end());
    int ans = A[0]^A[1]; 
    for(int i= 2;i<A.size();i++)
    {
        ans = min(ans,A[i]^A[i-1]);
    }
    return ans;
}
