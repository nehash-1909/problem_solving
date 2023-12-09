/*********************************************************************************************************************************
6. Single Number III

Given an array of positive integers A, two integers appear only once, and all the other integers appear twice. 
Find the two integers that appear only once.

Note: Return the two numbers in ascending order.
*********************************************************************************************************************************/

// Solution
vector<int> Solution::solve(vector<int> &A) {
    // first  set bit
    int maxVal = *max_element(A.begin(),A.end());
    vector<int> ans(2,0);
    int n = A.size();
    int temp = 0;
    int setBit = 0;
    for(int i=0;i<n;i++)
    {
        temp ^= A[i]; 
    }
    /*
    Gives first set bit from left
    */
    setBit = (temp&(temp-1))^temp; 


    for(int i=0;i<n;i++)
    {
        if((setBit)&A[i])
        {

            ans[0] ^= A[i];
        }
        else
        {
            ans[1] ^= A[i];
        }
    }
    int x = min(ans[0],ans[1]);
    int y = max(ans[0],ans[1]);
    return vector < int > {x,y};
}
