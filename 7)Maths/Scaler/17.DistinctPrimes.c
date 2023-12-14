/*********************************************************************************************************************************
17. Distinct Primes
You have given an array A having N integers. Let say G is the product of all elements of A.

You have to find the number of distinct prime divisors of G.
*********************************************************************************************************************************/

// Solution
const int values = 1e5 + 5;
vector<int> primes[values];
void sieve()
{

    for(int i=2;i<=values;i++)
    {
        if(primes[i].empty())
        {
            primes[i].push_back(i);
            for(int j=2*i;j<=values;j+=i)
            {
                primes[j].push_back(i);
            }
        }
    }
}
int Solution::solve(vector<int> &A) {
    sieve();
    set<int> s;
    for(int i=0;i<A.size();i++)
    {
        for(auto &i: primes[A[i]])
        {
            s.insert(i);
        }
    }
    return s.size();
}
