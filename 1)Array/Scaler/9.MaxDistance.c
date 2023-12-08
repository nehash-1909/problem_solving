/*********************************************************************************************************************************
9. Max Distance
Given an array, A of integers of size N. Find the maximum value of j - i such that A[i] <= A[j].
*********************************************************************************************************************************/

//Solution

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    if(n==1)
    {
        return 0;
    }
    int ans = -INT_MAX;
    vector<int> maxVal(n,0);

    maxVal[n-1] = A[n-1];
    for(int i =n-2;i>=0;i--)
    {
        maxVal[i] = max(maxVal[i+1],A[i]);
    }
    int l =0;
    int r=0;
    while(l<n && r<n)
    {
        
        if(A[l]<=maxVal[r])
        {
            ans = max(ans,r-l);
            r++;
        }
        else
        {
            l++;
        }
    }
    return ans;
}

