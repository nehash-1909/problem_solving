/*********************************************************************************************************************************
5. Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

*********************************************************************************************************************************/

// Solution

class Solution {
public:
    int maxArea(vector<int>& height) {

        int l = 0;
        int r = height.size()-1;
        int res = 0;

        int area = 1;
        while(l<r)
        {
            area = (r-l)*min(height[l],height[r]);
            res = max(res,area);
            if(height[l]<height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        return res;

    }
};
