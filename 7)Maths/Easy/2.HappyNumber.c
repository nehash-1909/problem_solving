/*********************************************************************************************************************************
2. Happy Number

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.
*********************************************************************************************************************************/

// Solution
class Solution {
public:
    int detect_cycle(int n)
    {
        int ans =0;
        while(n)
        {
            int rem  = n%10;
            ans += (rem)*(rem);
            n = n/10;
        }
        return ans;
    }
    bool isHappy(int n)
    {
        int slow = detect_cycle(n), fast = detect_cycle(detect_cycle(n));

        while(slow!=fast)
        {
            slow = detect_cycle(slow);
            fast = detect_cycle(detect_cycle(fast));
        }

        return (slow==1);
        
    }
};
