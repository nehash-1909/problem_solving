/*********************************************************************************************************************************
11. Sum the Difference

Given an integer array, A of size N.
You have to find all possible non-empty subsequences of the array of numbers and then,
for each subsequence, find the difference between the largest and smallest number in that subsequence.
Then add up all the differences to get the number.

As the number may be large, output the number modulo 1e9 + 7 (1000000007).

NOTE: Subsequence can be non-contiguous.
*********************************************************************************************************************************/

// Solution

long long mod = 1000000007;
long long largerPow(long long a,long long b)
{
    if(b==0)
    {
        return 1;
    }
    long long mid = largerPow(a,b/2);
    long long res = ((mid%mod)*(mid%mod))%mod;
    if(b%2==1)
    {
        res = ((res%mod)*(a%mod))%mod;
    }

    return res;

}
int Solution::solve(vector<int> &A) {
    /*
        After sorting the array, for every element,
        number of subsets where arr[i] is the smallest element = 2^i
        number of subsets where arr[i] is the largest element = 2^(N-i-1)
        So, contribution of arr[i] in our ans = arr[i] * (2^(N-i-1) - 2^i)
    */
    sort(A.begin(),A.end());
    int n = A.size();
    // 1 2 3 4 5
    // 0 1 2 3 4
    // for 3 smallest: i+1
    // for 3 largest: (n-i-1) => 5-2-1 = 2
    long long smallestVal = 0;
    long long largestVal = 0;
    for(int i=0;i<n;i++)
    {
        largestVal  = largestVal + A[i]*largerPow(2,i);
        smallestVal = smallestVal + A[i]*largerPow(2,n-i-1);
    }
    return (largestVal-smallestVal+mod)%mod;
}
