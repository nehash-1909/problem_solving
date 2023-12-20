/*********************************************************************************************************************************
12. QuickSort
Given an integer array A, sort the array using QuickSort.
*********************************************************************************************************************************/

// Solution

int partition(vector<int> &A,int s, int e)
{
    int l = s+1;
    int r = e;
    int pivot = A[s];
    while(l<=r)
    {
        if(A[l]<=pivot)
        {
            l++;
        }
        else if(A[r]>pivot)
        {
            r--;
        }
        else{
            swap(A[l],A[r]);
            l++;
            r--;
        }
    }
    swap(A[r],A[s]);
    return r;
}
void quick_sort(vector<int> &A,int l, int r)
{
    if(l>r)
        return;
    int pivot = partition(A,l,r);
    quick_sort(A,l,pivot-1);
    quick_sort(A,pivot+1,r);
}
vector<int> Solution::solve(vector<int> &A) {
    quick_sort(A,0,A.size()-1);
    return A;
}
