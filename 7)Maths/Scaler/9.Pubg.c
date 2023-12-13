/*********************************************************************************************************************************
9. Pubg
There are N players, each with strength A[i]. when player i attack player j, player j strength reduces to max(0, A[j]-A[i]). When a player's strength reaches zero, it loses the game, and the game continues in the same manner among other players until only 1 survivor remains.

Can you tell the minimum health last surviving person can have?
*********************************************************************************************************************************/

// Solution
int gcdVal(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    return gcdVal(b,a%b);
}
int Solution::solve(vector<int> &A) {
    int ans = 0;
    for(int i=0;i<A.size();i++)
    {
        ans = gcdVal(ans,A[i]);
    }
    return ans;
}
