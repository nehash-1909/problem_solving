/*********************************************************************************************************************************
5. Valid Square
Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.

The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

A valid square has four equal sides with positive length and four equal angles (90-degree angles).
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    int get_length(vector<int>& a, vector<int>& b)
    {
        int p1 = a[0] - b[0];
        int p2 = a[1] - b[1];
        return p1*p1 + p2*p2;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> sides = {
            get_length(p1,p2),
            get_length(p1,p3),
            get_length(p1,p4),
            get_length(p2,p3),
            get_length(p2,p4),
            get_length(p3,p4),
        };
        unordered_map<int,int> map;
        for(auto& i:sides)
        {
            if(i==0)
                return false;
            if(map.find(i)==map.end())
            {
                map[i] = 1;
            }
            else
            {
                map[i]++;
            }
        }
        if(map.size()!=2)
            return false;
        for(auto& i:map)
        {
            //cout<<" i "<<i.second;
            return (i.second==4 ||i.second==2);
        }
        return false;
        
    }
};
