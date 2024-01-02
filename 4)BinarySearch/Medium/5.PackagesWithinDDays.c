/*********************************************************************************************************************************
5. Capacity To Ship Packages Within D Days

A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the
conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
*********************************************************************************************************************************/
// Solution

class Solution {
public:
    bool idealWeight(vector<int>& weights,int m, int days) {
        int count = 0;
        int val = 1;
        for(int i=0;i<weights.size();i++)
        {
            count += weights[i];
            if(count>m)
            {
                count = weights[i];
                val++;
            }
        }

        if(val<=days)
        {
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        /*
            We can check what can be lowest weight capacity
            using binary search, in this l = max(weight) as
            weight cant come down less than the max element
            and if days are 1 then max weight capacity could be
            sum of all weights, so r = sum(weight)
            now calculate mid and think it as potential ans
            if mid weight is able to cover all the weights within
            given days, then store it in ans, and try to reduse the
            r.
        */
        int l = *max_element(weights.begin(),weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(idealWeight(weights,m,days))
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
