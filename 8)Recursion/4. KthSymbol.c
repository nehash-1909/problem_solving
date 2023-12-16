/*********************************************************************************************************************************
4. Kth Symbol

On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

Given row number A and index B, return the Bth indexed symbol in row A. (The values of B are 1-indexed.).
*********************************************************************************************************************************/

// Solution
int Solution::solve(int A, int B) {
    if(A==0)
        return 0;
    /*
    Every n+1 row element is made from every n rows element
    so n+1 row i index came from nth row i/2 index.
    if b is even then b/2 comes ok, bt if b is even then b/2+1
    here 0 --> 01, 1 --> 10
    so odd bits are same but even bits are getting reversed
    ========================================================
    Row 1: 0
    Row 2: 01
    Row 3: 01|10
    Row 4: 01|10|10|01
    Row 5: 0110100110010110
    */
    int res = solve(A-1,B/2+B%2);
    if(B%2==1)
        return res;
    return ((res==0)?1:0);
}
