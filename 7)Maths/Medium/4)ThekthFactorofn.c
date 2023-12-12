/*********************************************************************************************************************************
4. The kth Factor of n

You are given two positive integers n and k. A factor of an integer n is defined as an integer i where n % i == 0.

Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.
*********************************************************************************************************************************/

// Solution
class Solution {
public:
    int kthFactor(int n, int k) {
        // if(k==1)
        //     return 1;
        // int fact = 1;
        // int sqrt_n = n/2; 
        // for(int i=2;i<=n;i++)
        // {
        //     if(n%i==0)
        //     {
        //         fact++;
        //     }
        //     if(fact==k)
        //         return i;
        // }
        // return -1;

        vector<int> factors;

        int i=1;
        for(i=1;i*i<=n;i++)
        {   
            if(n%i==0 && --k==0)
            {
                return i;
            }
        }   
        
        for(i=i-1;i>=1;i--)
        {
            if(i*i==n)
            {
                continue;
            }
            if(n%i==0 && --k==0)
            {
                return n/i;
            }
        }
        return -1;
        
    }
};
