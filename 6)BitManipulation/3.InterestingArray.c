/*********************************************************************************************************************************
3. Interesting Array

You have an array A with N elements. We have two types of operation available on this array :
We can split an element B into two elements, C and D, such that B = C + D.
We can merge two elements, P and Q, to one element, R, such that R = P ^ Q i.e., XOR of P and Q.
You have to determine whether it is possible to convert array A to size 1, containing a single element equal to 0 after several splits and/or merge?
*********************************************************************************************************************************/

// Solution

string Solution::solve(vector < int > & A) {
    int i, ctr = 0;
    for (i = 0; i < A.size(); i++) {
        if (A[i] % 2)
            ctr++;
    }
    // checks the parity of the number of odd elements
    if (ctr % 2)
        return "No";
    else
        return "Yes";
}
