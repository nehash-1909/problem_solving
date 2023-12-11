/*********************************************************************************************************************************
6. Power of Two
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
        {
            return false;
        }
        // 4    => 0 0 0 0 0 1 0 0
        // 3    => 0 0 0 0 0 0 1 1
        // ~3   => 1 1 1 1 1 1 0 0
        // 4&~3 => 0 0 0 0 0 1 0 0 ==> 4
        if((n&~(n-1))==n)
        {
            return true;
        }

        return false;
    }
};
