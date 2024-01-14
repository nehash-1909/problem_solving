/*********************************************************************************************************************************
4.Largest Continuous Sequence Zero Sum

Given an array A of N integers.

Find the largest continuous sequence in a array which sums to zero.
*********************************************************************************************************************************/
// Solution
vector<int> Solution::lszero(vector<int> &A) {
    pair<int,int> largestSeq = {-1,-1};
    unordered_map<long,int> map;

    int largest_len = INT_MIN;
    long long sum = 0;

    for(int i=0;i<A.size();i++)
    {
        sum += (long long)A[i];
        if (sum == 0)
        {
            largest_len = i + 1;
            largestSeq = {0, i} ;  
        }
        if((map.find(sum) != map.end()))
        {
            if((i-map[sum])>largest_len)
            {
                largest_len = i-map[sum];
                largestSeq = {map[sum]+1, i} ;   
            }
        }
        else
        {
            map[sum] = i;
        }
    }
    if(largestSeq.first == -1)
    {
        return {};
    }
    return vector<int> (A.begin()+largestSeq.first, A.begin()+largestSeq.second+1) ;
}
