/*********************************************************************************************************************************
4. Minimum Limit of Balls in a Bag

You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations.

You can perform the following operation at most maxOperations times:

Take any bag of balls and divide it into two new bags with a positive number of balls.
For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.
Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.

Return the minimum possible penalty after performing the operations.

E.g., Input: nums = [2,4,8,2], maxOperations = 4
Output: 2
Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,4,8,2] -> [2,2,2,2,2,2,2,2]
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    bool isPossible(vector<int>& nums, int m, int maxOperations)
    {
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            /*
                When nums[i] is perfectly divisible by m, then it will have 1 less operation
                e.g., nums[i] = 8, m = 2
                nums[i]/m = 4
                8 -> 4, 4
                8 -> 2, 2, 4
                8 -> 2, 2, 2, 2
                so ans = nums[i]/m - 1
            */
            ans += ((nums[i]-1)/m);
        }

        if(ans<=maxOperations)
        {
            return true;
        }
        return false;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {

        int l = 1;
        int r = *max_element(nums.begin(),nums.end());
        int ans = -1;
        /*
            we have to divide the elements into smaller element
            for that we can take search space from 1 to max_element
            now we can check one by one, is the calculated element
            can be the minimum penality, if yes, we can reduce the
            penality by making m = r-1, else we have to increase 
            penality.

        */
        while(l<=r)
        {
            int m = (l+r)/2;
            if(isPossible(nums,m,maxOperations))
            {
                ans = m;
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        return ans;
    }
};

