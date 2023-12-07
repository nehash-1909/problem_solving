/*********************************************************************************************************************************
14. K-diff Pairs in an Array

Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.
*********************************************************************************************************************************/

//Solution

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        int ans=0;
        unordered_map<int,int> map;


        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]]++;
        }

        for(auto i:map)
        {
            int temp = k+i.first;

            if(k==0)
            {
                if(i.second>1)
                {
                    ans++;
                }
            }
            else if(map.find(temp)!=map.end())
            {
                ans++;

            }
        }

        return ans;


        
        
        
    }
};
