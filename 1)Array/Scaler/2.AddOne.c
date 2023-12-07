/*********************************************************************************************************************************
2.Add One To Number

Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

// Input : [0 , 0, 1, 2, 3]
// Output : [1, 2, 4]
*********************************************************************************************************************************/

// Solution

vector<int> Solution::plusOne(vector<int> &A) {
    int indx = A.size()-1;

    while(indx>=0 && A[indx]==9)
    {
        A[indx] = 0;
        indx--;
    }

    if(indx<0)
    {
        A.insert(A.begin(),1,1);
    }
    else
    {
        A[indx]++;
    }
    indx = 0;
    while(A[indx]==0)
    {
        A.erase(A.begin() + indx);
    }

    return A;
}
