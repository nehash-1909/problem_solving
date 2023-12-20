/*********************************************************************************************************************************
14. Maximum & Minimum Magic

Given an array of integers A of size N where N is even.

Divide the array into two subsets such that

1.Length of both subset is equal.
2.Each element of A occurs in exactly one of these subset.
Magic number = sum of absolute difference of corresponding elements of subset.
*********************************************************************************************************************************/

// Solution

int mod = 1000000007;
vector<int> Solution::solve(vector<int> &A) {
    /*
    Initially, sort the array in ascending order.
    For the minimum magic, find the sum of the difference between adjacent elements in pairs of two.
    for i=1 ; i<n ; i+=2
        min_magic+=a[i]-a[i-1]
    For the maximum magic, find the sum of the difference between the two elements equidistant from the front and back of the array.
    for i=0 ; i<n/2 ; i++
        max_magic+=a[n/2+i]-a[i]
    */
    sort(A.begin(),A.end());
    vector<int> result;
    int sum=0;
    int n= A.size();
    for(int i=0;i<A.size()/2;i++)
    {
        sum = (sum + abs(A[n-i-1]-A[i])%mod)%mod;
    }
    result.push_back(sum);
    sum = 0;
    for(int i=1;i<A.size();i+=2)
    {
        sum = (sum + abs(A[i]-A[i-1])%mod)%mod;
    }
    result.push_back(sum);
    return result;    
}
