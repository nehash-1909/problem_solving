/*********************************************************************************************************************************
1.  Rearrange Array
Given an array A of size N. Rearrange the given array so that A[i] becomes A[A[i]] with O(1) extra space.
*********************************************************************************************************************************/

// Solution
void Solution::arrange(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    for(int i=0;i<A.size();i++)
    {
        A[i] *= n;
    }
    //0%4  9%4 6%4  15%4 
    // 0   9   6   15
    // 0+0 8+1 4+2 12+3
    // 0   2 1 3
    for(int i=0;i<A.size();i++)
    {
        int idx = A[i]/n;
        A[i] += A[idx]/n;
    }
    for(int i=0;i<A.size();i++)
    {
        A[i] = A[i]%n;
    }
}
