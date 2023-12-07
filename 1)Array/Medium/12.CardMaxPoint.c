/*********************************************************************************************************************************
12. Maximum Points You Can Obtain from Cards

There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
*********************************************************************************************************************************/

//Solution
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = -1;
        int l = 0;
        int r = cardPoints.size()-k;
        int sum = 0;

        for(int i=r;i<cardPoints.size();i++)
        {
            sum += cardPoints[i];
        }

        ans = sum;
        for(int i=r;i<cardPoints.size();i++)
        {
            
            sum = sum + cardPoints[l] - cardPoints[i];
            ans = max(ans,sum);
            l++;
        }

        return ans;
        
    }
};
