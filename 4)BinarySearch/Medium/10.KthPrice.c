/*********************************************************************************************************************************
10. KthPrice

Given the price list at which tickets for a flight were purchased, figure out the kth smallest price for the flight.
kth smallest price is the minimum possible n such that there are at least k price elements in the price list with value <= n.
In other words, if the price list was sorted, then A[k-1] ( k is 1 based, while the array is 0 based ).
*********************************************************************************************************************************/

// Solution

int ksmallest(const vector<int> &A, int m, int k)
{
    int counter = 0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]<=m)
            counter++;
    }
    return counter;
}
int Solution::solve(const vector<int> &A, int B) {
    /*
        A : [2 1 4 3 2]
        k : 3

        element 3 : 4th smallest
        3 > B
    */
    int l = *min_element(A.begin(), A.end());
    int r = *max_element(A.begin(), A.end());
    int counter = 0;
    int ans = 0;
    while(l<=r)
    {
        int m = (r-l)/2+l;
        int element =  ksmallest(A,m,B);
        if(element >= B)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}
