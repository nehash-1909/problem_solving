/*********************************************************************************************************************************
6. Inversion count in an array

Given an array of integers A. If i < j and A[i] > A[j], then the pair (i, j) is called an inversion of A. Find the total number of inversions of A modulo (109 + 7).
*********************************************************************************************************************************/

// Solution

int mod = 1000000007;

int mergeCount(vector<int> &A, int l, int m,int n)
{
    int inv_count =0;
    vector<int> l1;
    vector<int> l2;
    int l1_size = m-l+1;
    int l2_size = n-m;
    for(int i=l;i<=m;i++)
    {
        l1.push_back(A[i]);
    }
    for(int i=m+1;i<=n;i++)
    {
        l2.push_back(A[i]);
    }
    int s=0,e=0, r=l;
    while(s<l1_size && e<l2_size)
    {
        if(l1[s]<=l2[e])
        {
            A[r] = l1[s];
            r++;
            s++;
        }
        else{
            A[r] = l2[e];
            // total elements - current index, gives: no of elements A[i] greater than A[j]
            inv_count =( inv_count + l1_size-s)%mod; 
            r++;
            e++;
        }
    }
    if(s<l1_size)
    {
        while(s<l1_size)
        {
                A[r] = l1[s];
                r++;
                s++;
        }
    }
    if(e<l2_size)
    {
        while(e<l2_size)
        {

                A[r] = l2[e];
                r++;
                e++;
        }
    }
    return inv_count%mod;
}

int inversionCount(vector<int> &A,int s,int e)
{
    int inv_count = 0;
    if(s<e)
    {
        int m = (s+e)/2;
        inv_count = (inv_count+ inversionCount(A,s,m))%mod; // i) first half 
        inv_count = (inv_count+ inversionCount(A,m+1,e))%mod; // ii) second half 
        inv_count = (inv_count+mergeCount(A,s,m,e))%mod; // iii) across both
    }
    return inv_count%mod;
}
//try breaking the array into half and then sort
// then count inverse count in :
// i) first half ii) second half iii) across both
int Solution::solve(vector<int> &A) {
    return inversionCount(A,0,A.size()-1)%mod;
}
