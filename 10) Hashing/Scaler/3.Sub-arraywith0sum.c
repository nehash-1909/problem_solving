/*********************************************************************************************************************************
3.Sub-array with 0 sum

Given an array of integers A, find and return whether the given array contains a non-empty subarray with a sum equal to 0.

If the given array contains a sub-array with sum zero return 1, else return 0.
*********************************************************************************************************************************/

// Solution

int Solution::solve(vector<int> &A) {
    int result = 0;
    long long sum = 0;
    unordered_set<long> map;

    for(int i=0;i<A.size();i++)
    {
        sum += (long long)A[i];
        if(sum == 0 || (map.find(sum) != map.end()))
        {
            return true;
        }
        map.insert(sum);
    }
    return false;
}
