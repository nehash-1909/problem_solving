/*********************************************************************************************************************************
5. Chocolate Distribution

Given an array A of N integers where the i-th element represent the number of chocolates in the i-th packet.

There are B number of students, the task is to distribute chocolate packets following below conditions:

1. Each student gets one packets.
2. The difference between the number of chocolates given to any two students is minimum.
Return the minimum difference (that can be achieved) between the student who gets minimum number of chocolates and the student who gets maximum number of chocolates.

Note: If you can't give each student 1 packet, return 0.
*********************************************************************************************************************************/

//Solution
int Solution::solve(vector<int> &A, int B) {
    /*
    Sort the array.
    Find the minimum difference between all subarrays of size B.
    */
    if(A.size()==0 or B==0)
        return 0;

    sort(A.begin(),A.end());

    int minAns = INT_MAX;

    for(int i=0;i<=A.size()-B;i++)
    {
        minAns = min(minAns,A[i+B-1]-A[i]);
    }

    return minAns;
}
