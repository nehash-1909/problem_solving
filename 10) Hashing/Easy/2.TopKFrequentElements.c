/*********************************************************************************************************************************
2.Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<pair<int, int>> ans;
        vector<int> res;
        set<int> set;
        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]]++;
            set.insert(nums[i]);
        }

        for (auto it = set.begin(); it != set.end(); it++)
        {
            pair<int, int> temp;
            temp.first = map[*it];
            // second part of the pair
            temp.second = *it;
            ans.push_back(temp);
        }

        sort(ans.begin(), ans.end(), greater <>());

        for(int i=0;i<k;i++)
        {
            
            res.push_back(ans[i].second);
        }
        return res;
    }
};
