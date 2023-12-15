/*********************************************************************************************************************************
1. Pow(x, n)
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    double myPow(double x, int n) {
        // x^n 
        long long N = n;
        if(n==0)
        {
            return 1.0;
        }
        if(n<0)
        {
            N = abs(N);
            x = (1.0)/x;
        }
        if(N%2==1)
        {
            return x*myPow(x*x,N/2);
        }
        else
        {
            return myPow(x*x,N/2);
        }
    }
};
