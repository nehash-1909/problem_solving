/*********************************************************************************************************************************
12. All GCD Pair

Given an array of integers A of size N containing GCD of every possible pair of elements of another array.

Find and return the original numbers used to calculate the GCD array in any order. For example, if original numbers are {2, 8, 10} then the given array will be {2, 2, 2, 2, 8, 2, 2, 2, 10}.
*********************************************************************************************************************************/

// Solution

vector<int> Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    reverse(A.begin(), A.end());
    vector<int> gcd_original;
    unordered_map<int,int> gcd_pair_freq;
    for(int i=0;i<A.size();i++)
    {
        if(gcd_pair_freq[A[i]]>0)
        {
            gcd_pair_freq[A[i]]--; // means it is gcd of some pair so ignore
        }
        else
        {
            for(int j=0;j<gcd_original.size();j++)
            {
                int gcd_temp = __gcd(A[i],gcd_original[j]);
                gcd_pair_freq[gcd_temp] += 2; // Add to frequency for gcd(a,b) and gcd(b,a)
            }
            gcd_original.push_back(A[i]);
        }
    }
    return gcd_original;
}
