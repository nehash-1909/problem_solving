/*********************************************************************************************************************************
7. Delete one
Given an integer array A of size N. You have to delete one element such that the GCD(Greatest common divisor) of the remaining array is maximum.

Find the maximum value of GCD.
*********************************************************************************************************************************/

// Solution

int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}
int Solution::solve(vector<int> &A) {
    int gcdVal = A[0];
    int gcdReverse = A[A.size()-1];
    vector<int> gcdLeft(A.size()+1,0);
    vector<int> gcdRight(A.size()+1,0);
    for(int i=0;i<A.size();i++)
    {
        gcdLeft[i] = gcd(gcdVal,A[i]);
        gcdVal = gcdLeft[i];
        
    }

    for(int i=A.size()-1;i>=0;i--)
    {
        gcdRight[i] = gcd(gcdReverse,A[i]);
        gcdReverse = gcdRight[i];
    }
    int ans = 0;

    for(int i=0;i<A.size();i++)
    {
        if(i==0)
        {
            ans = max(ans,gcdRight[i+1]);
        }
        if(i==A.size()-1)
        {
            ans = max(ans,gcdLeft[i-1]);
        }
        ans = max(ans,gcd(gcdLeft[i-1],gcdRight[i+1]));
    }
    return ans;

}
