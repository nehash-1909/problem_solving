/*********************************************************************************************************************************
3. Aggressive cows

Farmer John has built a new long barn with N stalls. Given an array of integers A of size N where each element of the array 
represents the location of the stall and an integer B which represents the number of cows.

His cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting 
each other, John wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible.
What is the largest minimum distance?
*********************************************************************************************************************************/

// Solution

bool distancePossible(vector<int> &A, int m, int B)
{
    int cows = 1;
    int prevDist = 0;
    for(int i=1;i<A.size();i++)
    {
        /*
            m is the min distance required btwn the cows
            now we will take the cur cow and prev cow position
            if distance btwn cur cow - prev cow >=m ==> valid distance
            otherwise, distance needed to be increased, so i++;
        */
        if(A[i]-A[prevDist]>=m)
        {
            /*
                putting the cow in atleast m distance
            */
            cows++;
            prevDist = i;
        }
    }

    if(cows>=B)
    {
        return true;
    }
    return false;
}
int Solution::solve(vector<int> &A, int B) {

   int n = A.size();
   // Sorting is required only then we can get min distance btwn stalls
   sort(A.begin(), A.end());

   int l = 1; // min distance can go upto 1
   int r = A[n-1]-A[0];
   int ans = -1;
    while(l<=r)
    {
        int m = (l+r)/2;
        // calculate min distance
        if(distancePossible(A,m,B))
        {
            // distance should be largest
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
