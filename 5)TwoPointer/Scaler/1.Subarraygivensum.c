/*********************************************************************************************************************************
1. Subarray with given sum

Given an array of positive integers A and an integer B, find and return first continuous subarray which adds to B.

If the answer does not exist return an array with a single integer "-1".

First sub-array means the sub-array for which starting index in minimum.
*********************************************************************************************************************************/

// Solution
vector<int> Solution::solve(vector<int> &A, int B) {
    int l = 0;
    int r = 0;
    vector<long long> prefix_Sum(A.size(), 0);
    vector<int> res;

    prefix_Sum[0] = A[0];

    for (int i = 1; i < A.size(); i++) {
        prefix_Sum[i] = prefix_Sum[i - 1] + (long long)A[i];
    }

    while (l < A.size() && r < A.size()) {
        long long temp = prefix_Sum[r] - (l > 0 ? prefix_Sum[l - 1] : 0);
        if (temp == (long long)B) {
            for (int i = l; i <= r; i++) {
                res.push_back(A[i]);
            }
            return res;
        } else if (temp < B) {
            r++;
        } else {
            l++;
        }
    }
    res.push_back(-1);
    return res;
}
