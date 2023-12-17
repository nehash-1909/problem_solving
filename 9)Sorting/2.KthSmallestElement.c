/*********************************************************************************************************************************
2. Kth Smallest Element
Find the Bth smallest element in given array A .

NOTE: Users should try to solve it in less than equal to B swaps.
*********************************************************************************************************************************/

// Solution
int Solution::kthsmallest(const vector<int> &A, int B) {
    vector<int> a = A;
    for( int i=0;i<B;i++)
    {
        int min_val = i;
        for( int j=i+1;j<a.size();j++)
        {
            if(a[j]<a[min_val])
            {
                min_val = j;
            }
        }
        swap(a[i],a[min_val]);
    }
    return a[B-1];
}

