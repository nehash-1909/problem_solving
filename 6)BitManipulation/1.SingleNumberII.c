/*********************************************************************************************************************************
1. Single Number II

Given an array of integers, every element appears thrice except for one, which occurs once.

Find that element that does not appear thrice.

NOTE: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?
*********************************************************************************************************************************/

// Solution

int Solution::singleNumber(const vector<int> &A) {
    int maxVal = *max_element(A.begin(),A.end());
    int res = 0;
    int len = 1;
    while(len<=maxVal)
    {
        int count_set_bits = 0;
        for(int i=0;i<A.size();i++)
        {
            
            if(A[i]&len)
            {
                count_set_bits++;
            }
        }
        if((count_set_bits%3)==1)
        {
            res +=len;
        }
        len = len<<1;
    }
    return res;
}
