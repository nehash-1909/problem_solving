/*********************************************************************************************************************************
5. Distinct Numbers in Window

You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all windows of size B.

Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence 
Ai, Ai+1 ,..., Ai+B-1.

NOTE: if B > N, return an empty array.
*********************************************************************************************************************************/

// Solution
vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int,int> map;
    vector<int> res;
    int count = 0;

    for(int i=0;i<B;i++)
    {
        if(map.find(A[i]) == map.end())
        {
            count++;
        }
        map[A[i]]++;
    }
    res.push_back(count);

    for(int i=B;i<A.size();i++)
    {
        
        map[A[i-B]]--;
        if(map[A[i-B]] <= 0)
        {
            map.erase(A[i-B]);
            count--;
        }
        if(map.find(A[i]) == map.end())
        {
            count++;
        }
        map[A[i]]++;
        res.push_back(count);
    }
    return res;
}
