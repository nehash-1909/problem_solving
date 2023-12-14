/*********************************************************************************************************************************
13. Prime Sum
Given an even number A ( greater than 2 ), return two prime numbers whose sum will be equal to the given number.
*********************************************************************************************************************************/

//Solution
vector<bool> sieveofEra(int A)
{
    vector<bool> isPrime(A+1,true);
    isPrime[1] = false;
    isPrime[0] = false;
    for(int i=2;i<=sqrt(A);i++)
    {
        if(isPrime[i]==false)
        {
            continue;
        }
        for(int j=i*i;j<=A;j+=i)
        {
            isPrime[j] = false;
        }

    }
    return isPrime;

}
vector<int> Solution::primesum(int A) {
    vector<int> ans(2,0);
    vector<bool> isPrime = sieveofEra(A);
    for(int i=2;i<=A;i++)
    {
        if(isPrime[i]&&isPrime[A-i])
        {
            
            ans[0] = i;
            ans[1] = A-i;
            break;
        }
    }
    return ans;
    
}
