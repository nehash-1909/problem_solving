/*********************************************************************************************************************************
2. Sqrt(x)
Given a non-negative integer x, return the square root of x rounded down to the nearest integer.
The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    int mySqrt(int x) {
        // Base cases
        if (x == 0 || x == 1)
        {
            return x;
        }
        int l = 1;
        int r = x/2;
        int ans;
        while(l<=r)
        {
            long long m = (l+r)/2;
            if(m*m >(long long)x)
            {
                r = m-1; 
            }
            else
            {
                l = m+1;
                ans = m;
            }
        }
        return ans;
    }
};
