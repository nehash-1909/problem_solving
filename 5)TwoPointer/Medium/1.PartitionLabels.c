/*********************************************************************************************************************************
1. Partition Labels
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
Return a list of integers representing the size of these parts.
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> map(26,0);
        for(int i=0;i<s.length();i++)
        {
            map[s[i]-'a'] = i;
        }
        int l =0, r = 0;

        for(int i=0;i<s.length();i++)
        {
            /*
                0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
                a b a b c b a c a d e  f  e  g  d  e  h  i  j  h  k  l  i  j
                a = 8
                b = 5
                c = 7
                d = 14
                e = 15
                f = 11
                g = 13
                h = 19
                i = 22
                j = 23
                k = 20
                l = 21
            */

            r = max(map[s[i]-'a'],r);
            
            if(r==i)
            {
                ans.push_back(i-l+1);
                l = i+1;
            }
        }
        return ans;
    }
};
