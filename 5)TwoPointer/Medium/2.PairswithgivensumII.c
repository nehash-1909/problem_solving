/*********************************************************************************************************************************
2. Pairs with given sum II
Given a sorted array of integers (not necessarily distinct) A and an integer B, find and return how many pair of integers ( A[i], A[j] ) 
such that i != j have sum equal to B.

Since the number of such pairs can be very large, return number of such pairs modulo (109 + 7).
*********************************************************************************************************************************/

// Solution

int Solution::solve(vector<int> &A, int B) {
    int l =0;
    int n = A.size();
    int r = A.size()-1;
    long mod = 1000000007;
    long count =0;

    while(l<r)
    {
        int sum = A[l] + A[r];
        if(sum == B)
        {
            // elements not distinct
            // if A[i] and A[j] are equal then no of count: n*(n-1)/2
            // else A[i] != A[j] A[i]*A[j]
            if(A[l] == A[r])
            {
                int cnt = r-l+1;
                count = (count + ((cnt)*1l*(cnt-1)/2)%mod)%mod;
                break;
            }
            else
            {
                int cnt_l = 1, cnt_r = 1;
                while(l+1<r && A[l] == A[l+1])
                {
                    cnt_l++;
                    l++;
                }
                while(r-1>l && A[r] == A[r-1])
                {
                    cnt_r++;
                    r--;
                }
                count = (count + (cnt_l*1l*cnt_r)%mod)%mod;
                l++;
                r--;
            }
        }
        else if(sum > B)
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    return count%mod;
}
