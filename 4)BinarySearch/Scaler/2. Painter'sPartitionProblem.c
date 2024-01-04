/*********************************************************************************************************************************
2. Painter's Partition Problem

Given 2 integers A and B and an array of integers C of size N. Element C[i] represents the length of ith board.
You have to paint all N boards [C0, C1, C2, C3 … CN-1]. There are A painters available and each of them takes B units of time to paint 1 unit of the board.

Calculate and return the minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of the board.
NOTE:
1. 2 painters cannot share a board to paint. That is to say, a board cannot be painted partially by one painter, and partially by another.
2. A painter will only paint contiguous boards. This means a configuration where painter 1 paints boards 1 and 3 but not 2 is invalid.

Return the ans % 10000003.
*********************************************************************************************************************************/

// Solution

int check_painter(vector<int> &C,int A,int m)
{
    long long count = 0;
    int painter = 1;

    for(int i=0;i<C.size();i++)
    {
        count += C[i];
        if(count>m)
        {
            count = C[i];
            painter++;
        }
    }
    if(painter<=A)
    {
        return true;
    }
    return false;
}
int Solution::paint(int A, int B, vector<int> &C) {
    int mod = 10000003;
    long l = *max_element(C.begin(), C.end());
    long r = 0;
    for(auto i:C)
    {
        r += (long)i;
    }

    long ans = -1;

    while(l<=r)
    {
        int m = (l+r)/2;
        if(check_painter(C,A,m))
        {
            ans  = m%mod;
            r = m-1;
        }
        else
        {
            l = m+1;
        }
    }
    return (ans*B)%mod;
}
