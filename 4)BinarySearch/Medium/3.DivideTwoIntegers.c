/*********************************************************************************************************************************
3. Divide Two Integers
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part.
For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    long long multiplyTwoNumbers(long long a, long long b) {
    long long result = 0;
    while (b > 0) {
        if (b & 1) {
            result += a;
            }
        a = a << 1;
        b = b >> 1;
    }
    return result;
    }
    int divide(int dividend, int divisor) {
        long long op = pow(2,31);
        long long l = 0;
        long long r = abs(dividend);
        long long ans = 0;
        // Quotient(ans) * divisor = dividend
        while(l<=r)
        {
            long long m = (l+r)/2;
            if(multiplyTwoNumbers((long long )abs(m),(long long )abs(divisor))<=(long long)abs(dividend))
            {
                ans = m;
                l = m+1;
            }
            else
            {
                r = m-1;
            }
        }
        if(dividend>=0 && divisor<0 || dividend<0 && divisor>=0) ans*=-1;
        if(ans>0) return min(op-1,ans);
        else return max(-1*op,ans);
    }
};
