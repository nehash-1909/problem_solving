/*********************************************************************************************************************************
4. Food Packets Distribution

The government wants to set up B distribution offices across N cities for the distribution of food packets.

The population of the ith city is A[i]. Each city must have at least 1 office and every person is assigned to exactly one office
in their own city.

Let M denote the minimum number of people that are assigned to any of the offices. Find the maximum value of M possible.
*********************************************************************************************************************************/
// Solution

bool _ispossible(vector<int> &A,int k, int B)
{
    int offices  = 0;
    for(auto i: A)
    {
        offices += i/k;
    }
    /*
       1000 2200 3600
       k = 500, B= 6
       offices = 2 + 4 + 7 = 13>B offices I can have

       // if we can have more offices, than required people will always get food

       k = 1100
       offices = 0 + 2 + 3 = 5< B offices I can have

       // if we can have less offices, than required people will not get food
    */
    if(offices>=B)
    {
        return true;
    }
    return false;
}
int Solution::solve(vector<int> &A, int B) {
    int l= 1;
    /*
        we have to distribute food to A[i] people
        in n offices.

        we want minimum val,
        so l = 1 , minimum number of people that can be assigned 
        r = min(A), maximum can be the min array value
    */
    int ans=-1;
    int r = A[0];
    long sum = 0;
    for(int i=0;i<A.size();i++)
    {
        /*
            This is to check if number of people
            are less than number of office
        */
        sum+=A[i];
        /*
            This is to check max number of people possible
            to be assigned to any of the offices. We can't
            assign more than min element for all cities.
        */
        r = min(A[i],r);
    }
    if(sum<B)
        return 0;
    while(l<=r)
    {
        int m = (l+r)/2;
        if(_ispossible(A,m,B))
        {
            ans = m;
            l = m+1;
        }
        else
        {
            r = m-1;
        }
    }

    return ans;
}
