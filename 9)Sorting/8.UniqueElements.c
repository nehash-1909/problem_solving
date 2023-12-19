/*********************************************************************************************************************************
8. Unique Elements

You are given an array A of N elements. You have to make all elements unique. To do so, in one step you can increase any number by one.

Find the minimum number of steps.
*********************************************************************************************************************************/

// Solution

int Solution::solve(vector<int> &A) {
    /*
        Sort
        if A[i-1] = A[i], then increment A[i] & count by 1 
        if A[i-1] > A[i], then increment A[i] & count by A[i-1]-A[i]+1 

               2 4 3 4 5 3
        Sort:  2 3 3 4 4 5
        scan1: 2 3 4 4 4 5, A[i-1] = A[i] 4==4, add 1
        scan2: 2 3 4 5 4 5, A[i-1] > A[i] 5>4, add 2
        scan3: 2 3 4 5 6 5, A[i-1] > A[i] 5>4, add 2
        scan4: 2 3 4 5 6 7, unique elements
    */
    sort(A.begin(),A.end());
    int count = 0;

    for(int i=1;i<A.size();i++)
    {
        if(A[i-1]>=A[i])
        {
            int diff = A[i-1]-A[i]+1;
            A[i]=A[i]+diff;
            count+=diff;
        }
    }
    return count;
}
