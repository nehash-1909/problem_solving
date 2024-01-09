/*********************************************************************************************************************************
3. Closest pair from sorted arrays

Given two sorted arrays of distinct integers, A and B, and an integer C, find and return the pair whose sum is closest to C and 
the pair has one element from each array.

More formally, find A[i] and B[j] such that abs((A[i] + B[j]) - C) has minimum value.

If there are multiple solutions find the one with minimum i and even if there are multiple values of j for the same i then 
return the one with minimum j.

Return an array with two elements {A[i], B[j]}.
*********************************************************************************************************************************/

// Solution

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int l = 0;
    int r = B.size()-1;
    int diff = abs(A[l]+B[r]-C);
    vector<int> res;
    int ans[2];
    ans[0] = A[l];
    ans[1] = B[r];
    while((l < A.size())&&(r>=0))
    {
        int cur_diff = abs(A[l]+B[r]-C);
        if(cur_diff<=diff)
        {
            if(cur_diff==diff)
            {
                if(ans[0]>A[l])
                {
                    ans[0]=A[l];
                }
                else if(ans[0]==A[l] && ans[1]>B[r])
                {
                    ans[1]=B[r];
                }
            }
            else
            {
                diff = cur_diff;
                ans[0] = A[l];
                ans[1] = B[r];
            }
        }
        if(A[l]+B[r]>C)
        {
            r--;
        }
        else{
            l++;
        }
    }
    res.push_back(ans[0]);
    res.push_back(ans[1]);
    return res;
}
