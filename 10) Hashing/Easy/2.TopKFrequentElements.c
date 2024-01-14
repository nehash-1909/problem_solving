/*********************************************************************************************************************************
2.Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    static bool cmp(pair<int,int>a , pair<int,int>b)
    {
        return a.first>b.first;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<pair<int,int>> v;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]]++;
        }
        for(auto m: map)
        {
            pair<int,int> p;
            p.first = m.second;
            p.second = m.first;

            v.push_back(p);
        }

        sort(v.begin(), v.end(), cmp);

        for(int i=0;i<k;i++)
        {  
            res.push_back(v[i].second);
        }
        return res;
    }
};
