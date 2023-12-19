/*********************************************************************************************************************************
9. Reverse pairs

Given an array of integers A, we call (i, j) an important reverse pair if i < j and A[i] > 2*A[j].
Return the number of important reverse pairs in the given array A.
*********************************************************************************************************************************/

// Solution

int mod = 1000000007;

int merge(vector<int> &A, int l, int m,int n)
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
        if((long)l1[s]>2*(long)l2[e])
        {
            inv_count =( inv_count + l1_size-s)%mod;
            e++; // only incrementing on this condition
        }
        else{
            s++;
        }
    }
    s=0;
    e=0;
    r=l;
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
int mergeSort(vector<int> &A, int l, int r)
{
    int inv_count = 0;
     if(r>l){
    int m = (r+l)/2;
    inv_count = (inv_count+mergeSort(A,l,m))%mod;
    inv_count = (inv_count+mergeSort(A,m+1,r))%mod;
    inv_count = (inv_count+merge(A,l,m,r))%mod;
     }
    return inv_count%mod;
}
int Solution::solve(vector<int> &A) {

    return mergeSort(A,0,A.size()-1);
}
