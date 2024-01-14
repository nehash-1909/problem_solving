/*********************************************************************************************************************************
2. Shaggy and distances

Shaggy has an array A consisting of N elements. We call a pair of distinct indices in that array a special if elements at those 
indices in the array are equal.
  
Shaggy wants you to find a special pair such that the distance between that pair is minimum. 
Distance between two indices is defined as |i-j|. If there is no special pair in the array, then return -1.
*********************************************************************************************************************************/

// Solution

int Solution::solve(vector<int> &A) {
    unordered_map<int,int> map;
    int min_distance =  INT_MAX;
    for(int i=0;i<A.size();i++)
    {    
        if(map.find(A[i])!=map.end())
        {
            min_distance = min(min_distance,abs(i-map[A[i]]));
        }
        map[A[i]] = i;
    }
    if(min_distance == INT_MAX)
    {
        return -1;
    }
    return min_distance;
}
